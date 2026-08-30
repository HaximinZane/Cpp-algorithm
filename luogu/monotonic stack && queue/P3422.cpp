#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 10;
long long datas[N][2];
long long ls[2 * N], rs[2 * N], pl[2 * N], pr[2 * N];
bool st[N];
int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> datas[i][0] >> datas[i][1];
    }
    datas[0][1] = datas[n][1];
    for (long long i = 1; i <= n; i++)
        ls[i] = datas[i][0] - datas[i][1];

    for (long long i = n; i >= 1; i--)
        rs[i] = datas[i][0] - datas[i - 1][1];

    for (long long i = n + 1; i <= 2 * n; i++)
        ls[i] = ls[i - n], rs[i] = rs[i - n];

    for (long long i = 1; i <= 2 * n; i++)
    {
        pl[i] = pl[i - 1] + ls[i];
    }
    for (long long i = 1; i <= 2 * n; i++)
    {
        pr[i] = pr[i - 1] + rs[i];
    }

    deque<long long> lq, rq;
    lq.push_back(0);
    rq.push_back(0);

    for (long long i = 1; i <= 2 * n - 1; i++)
    {

        while (!lq.empty() && i - lq.front() > n+1)
            lq.pop_front();
        if (i > n)
        {
            if (pl[lq.front()] - pl[i - n - 1] >= 0)
                st[i - n] = 1;
        }
        while (!lq.empty() && pl[lq.back()] >= pl[i])
            lq.pop_back();
        lq.push_back(i);
    }

    for (long long i = 1; i <= 2 * n - 1; i++)
    {
        while (!rq.empty() && i - rq.front() > n)
            rq.pop_front();
        if (i >= n)
        {
            // pr[n] 表示：从n反方向出发走向n的花费
            if (pr[i] - pr[rq.front()] >= 0)
                st[i % n] = 1;
        }
        while (!rq.empty() && pr[rq.back()] <= pr[i])
            rq.pop_back();
        rq.push_back(i);
    }
    st[n] = st[0];
    for (long long i = 1; i <= n; i++)
    {
        if (st[i])
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
}