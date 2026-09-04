#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll qmi(ll a, ll b, ll p){
    ll t = a;
    ll res = 1;
    while(b){
        if(b & 1) res = res * t % p;
        b >>= 1;
        t = t*t % p;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        ll a,p;
        cin >> a >> p;
        // 求逆元，ax mod p == 1
        // 由费马小定理，a^(p-1) mod p == 1
        // 故逆元为 a^p-2 ，最后 mod p 限制一下
        // 快速幂搞定
        if(a%p==0) cout << "impossible" << '\n';
        else 
            cout << qmi(a,p-2,p) << '\n';
     }
}