#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5,mod = 1e9 + 7;

ll bang[N],nbang[N];

ll qmi(int a,int p){
    // 针对素数求逆元
    ll b = p-2;
    ll t = a;
    ll res = 1;
    while(b){
        if(b&1) res = res * t % mod;
        b >>= 1;
        t = t * t % mod;
    }
    return res;
}


void init(){
    // 核心公式是 Ca,b = a!/(b!*(a-b)!)
    // 由于 a,b 在 1e5 先 O(1e5) 地处理出所有阶乘即可
    // 分母上的阶乘，相当于乘它们的逆元
    for(int i = 1;i<=1e5;i++){
        bang[i] = i * bang[i-1] % mod;
        nbang[i] = qmi(bang[i], mod);
    }
}

int main(){
    int n;
    cin >> n;
    bang[0] = 1;

    init();

    while(n--){
        int a,b;
        cin >> a >> b;
        if(a==b){
            cout << 1 << '\n';
            continue;
        } 
        ll t = (bang[a] * nbang[b]) % mod;
        t = t * nbang[a-b] % mod;

        cout << t << '\n';
    }
}