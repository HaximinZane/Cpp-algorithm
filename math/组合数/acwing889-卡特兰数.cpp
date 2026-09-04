#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int p = 1e9 + 7;

ll qmi(ll a)
{
    // 快速幂求逆元
    int b = p - 2;
    ll res = 1, t = a;
    while (b)
    {
        if (b & 1)
            res = res * t % p;
        b >>= 1;
        t = t * t % p;
    }
    return res;
}

ll C(int a, int b)
{   
    // 朴素计算组合数
    ll res = 1, tmp = 1;
    for (int i = a, j = b; j > 0; j--, i--)
    {
        res = res * i % p;
        tmp = tmp * j % p;
    }
    res = res * qmi(tmp) % p;
    return res;
}

int main()
{
    // 重点在于卡特兰数的推导
    // 用画格子即可推出，是对角线上面1格那条线，然后做对称，最后是 C2n,n - C2n,n-1 = C2n,n / n+1
    // 注意所有 mod p 情况下的分母都要转变成 乘逆元
     
    int n;
    cin >> n;
    cout << C(2 * n, n) * qmi(n + 1) % p << '\n';
}
