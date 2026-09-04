#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }

    ll d = exgcd(b,a%b,y,x);

    y -= a/b * x;

    return d;
}



int main(){
    ll n;
    cin >> n;
    while(n--){
        ll a,b,m;
        cin >> a >> b >> m;
        /* 
            要找到 x 使得
            ax mod m == b mod m
            也就是 ax = km + b
            ax + (-k) m == b  找到 x 即可
            先判断 (a,m) 与 b 关系
            然后找到 exgcd 的 x，之后扩倍数 
        */
        ll x = 0,y = 0;
        ll d = exgcd(a,m,x,y);
        if(b%d) cout << "impossible" << '\n';

        else
        {
            x = x * (b / d) % m;
            cout << x << '\n';
        }
    }
}