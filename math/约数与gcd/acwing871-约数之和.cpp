#include<bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll,ll> mp;
const ll mod = 1e9 + 7;

void solve(ll a){
    for(int i = 2;i<=a/i;i++){
        while(a%i==0){
            mp[i]++;
            a /= i;
        }
    }
    if(a!=1) mp[a]++;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        ll a;
        cin >> a;
        solve(a);
    }

    ll ans = 1;

    // 下面的处理都是基于一个公式，质因数分解后，约数之和为
    // (p1^0 + ... + p1^a1) * ... * (pn^0 + ... + pn^an)
    for(auto x : mp){
        ll p = x.first , maxe = x.second;
        ll t = 1,tmp = p;
        for(ll i = 1;i<=maxe;i++){
            t = (t + tmp) % mod;
            tmp = tmp * p % mod;
        }
        ans = ans * t % mod;
    }
    cout << ans;   
}