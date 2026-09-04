#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        ll m = 1, t;
        while (m < n)
        {
            // t = m;
            // m = m + m / (k - 1) + 1;

            ll q = m / (k - 1);
            ll jmp = q + 1;

            // 临界点
            ll upmax = (q + 1) * (k - 1) - 1;

            // 跳过临界点的步数
            ll cnt = (upmax - m) / jmp + 1;


            if (m + cnt*jmp >= n)
            {
                ll steps = (n - 1 - m) / jmp;
                t = m + steps * jmp;
                break; 
            }
            m = m + cnt * jmp;
            t = m;
        }
        cout << t + 1 << '\n';
    }
}