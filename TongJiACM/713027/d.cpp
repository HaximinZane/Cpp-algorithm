#include <iostream>
using namespace std;
using ll = long long;

ll mul(ll x, ll y, ll m)
{
    ll res = 0;
    x %= m;
    y %= m;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res + x) % m;
        x = (x + x) % m;
        y /= 2;
    }
    return res;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}


ll C(ll n, ll m, ll c)
{
    if (m < 0 || m > n)
        return 0;
    if (m == 0 || m == n)
        return 1;
    m = min(m, n - m);
    ll num = 1, e = 1;
    for (ll i = 1; i <= m; ++i)
    {
        num = (num * (n - i + 1)) % c;
        e = (e * i) % c;
    }
    ll x = 0, y = 0;
    exgcd(e, c, x, y);
    x =  (x % c + c) % c;
    return mul(num, x, c);
}

ll Lucas(ll n, ll m, ll c)
{
    if (m == 0)
        return 1;
    if (n < m)
        return 0;
    return mul(C(n % c, m % c, c), Lucas(n / c, m / c, c), c);
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    
    if (a < b)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (a == b || b == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    cout << Lucas(a - 1, b - 1, c) << "\n";

}