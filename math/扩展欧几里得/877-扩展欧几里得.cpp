#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void exgcd(ll a,ll b,ll& x,ll& y){
    
    if(b==0){
        x = 1,y = 0;
        return;
    }

    /*
        初始的x,y只是占位的用处，到递归最深处会有真正的值
        这个时候返回x,y
        然后我们推出，此时返回的x，y，与这一层的a，b关系是
        ax + b[ y - (a/b)*x ] = (a,b)
        于是我们需要调整一下y，让a,b,x,y满足 ax + by = (a,b)
        故 y -= (a/b) * x;
    */

    // 这里有个小trick，y和x反写
    exgcd(b, a%b ,y,x);
    
    y -= (a/b) * x;

}

int main(){
    ll n;
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b;
        ll x = 0,y = 0;
        exgcd(a,b,x,y);
        cout << x << ' ' << y << '\n';
    }
}