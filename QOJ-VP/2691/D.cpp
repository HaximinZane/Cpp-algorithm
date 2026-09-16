#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int INF = 1e9;

ll h[N];
int a[N][2];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> h[i];
    }
    stack<ll> l,r;
    for(int i = 1;i<=n;i++){
        a[i][0] = a[i][1] = INF;
    }
    for(int i = 1;i<=n;i++){
        while(!l.empty() && h[l.top()]<h[i]){
            l.pop();
        }
        if(!l.empty()) a[i][0] = i-l.top();
        l.push(i);

        while(!r.empty() && h[r.top()]<h[i]){
            int t = r.top();
            a[t][1] = i-t;
            r.pop();
        }
        r.push(i);
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        int tmp = min(a[i][0],a[i][1]);
        if(tmp==INF) continue;
        ans += tmp;
    }
    cout << ans;
}