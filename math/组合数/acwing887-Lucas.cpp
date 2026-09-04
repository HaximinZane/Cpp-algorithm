#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int p;

ll qmi(ll a,ll p){
    // 依旧快速幂求 模质数的逆元
    ll b = p-2;
    ll t = a;
    ll res = 1;
    while(b){
        if(b&1) res = res * t % p;
        b >>= 1;
        t = t * t % p; 
    }
    return res;
}


ll C(int a,int b){
    // 这里保证 a,b < 1e5，直接朴素就可以
    if(b==0 || a == b) return 1;
    if(a<b) return 0;
    ll res = 1,tmp = 1;
    for(int i = a,j = b;j>0;i--,j--){
        res = res * i % p;
        tmp = tmp * j % p;
    }
    res = res * qmi(tmp,p) % p;
    return res;
}


ll lucas(ll a,ll b){
    // Lucas 定理 Ca,b mod p = Ca%p,b%p * Ca/p,b/p mod p;
    if(a < p && b < p) return C(a,b) % p;
    else{
        return C(a%p,b%p) * lucas(a/p,b/p) % p;
    }
}



int main(){
    int n;
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b >> p;
        cout << lucas(a,b) << '\n';
    }
}