#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    ll l,r;
    ll v,lazy;
};

const int N = 1e5+10;
ll arr[N];
node tr[4*N];

void pushup(ll u){
    tr[u].v = tr[u<<1].v + tr[u<<1|1].v;
    tr[u].l = tr[u<<1].l;
    tr[u].r = tr[u<<1|1].r;
}
void build(ll u,ll l,ll r){
    if(l>r) return; 
    if(l==r){
        tr[u] = {l,r,arr[l],0};
        return;
    }
    ll mid = l + (r-l)/2;
    build(2*u,l,mid),build(2*u+1,mid+1,r);
    pushup(u);
}

void pushdown(ll u){
    if(tr[u].l == tr[u].r) return;
    if(tr[u].lazy==0) return;
    tr[u<<1].v += (tr[u<<1].r - tr[u<<1].l + 1) * tr[u].lazy;
    tr[u<<1|1].v += (tr[u<<1|1].r - tr[u<<1|1].l + 1) * tr[u].lazy;
    tr[u << 1].lazy += tr[u].lazy, tr[u << 1 | 1].lazy += tr[u].lazy;
    tr[u].lazy = 0;
}

void qmodify(ll aiml,ll aimr,ll u,ll lazy){
    ll ql = tr[u].l,qr = tr[u].r;
    if(aiml>qr || aimr < ql) return;
    if(aiml<=ql && aimr >= qr){
        tr[u].v += (qr-ql+1) * lazy;
        tr[u].lazy += lazy;
        return;
    }
    ll mid = ql + (qr-ql)/2;
    pushdown(u);
    if(aiml <= mid) qmodify(aiml,aimr,u*2,lazy);
    if(aimr >= mid+1) qmodify(aiml,aimr,u<<1|1,lazy);
    pushup(u);
}

ll query(ll aiml,ll aimr,ll u){
    ll ql = tr[u].l,qr = tr[u].r;
    if(aiml <= ql && aimr >= qr) return tr[u].v;
    ll res = 0;
    ll mid = ql + (qr-ql)/2;
    pushdown(u);
    if(aiml<=mid) res += query(aiml,aimr,u<<1);
    if(aimr >= mid + 1) res += query(aiml,aimr,u<<1|1);
    return res;
}
int main(){
    ll n,m;
    cin >> n >> m;
    for(ll i = 1;i<=n;i++) cin >> arr[i];
    build(1,1,n);
    while(m--){
        ll t;
        cin >> t;
        switch(t){
            case 1:
                ll x,y,k;
                cin >> x >> y >> k;
                qmodify(x,y,1,k);
                break;
            case 2:
                ll a,b;
                cin >> a >> b;
                cout << query(a,b,1) << '\n';
                break;
        }
    }
}