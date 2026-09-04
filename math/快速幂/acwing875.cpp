#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll qmi(ll a, ll b, ll p){

    // 快速幂的核心就在于把指数拆分成二进制
    ll t = a;
    ll res = 1;
    while(b){
        if(b & 1){
            res = res * t % p;
        }
        b >>= 1;
        t =  t * t % p;
    }
    return res;
}



int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b,p;
        cin >> a >> b >> p;
        cout << qmi(a,b,p) << '\n';
    }
}