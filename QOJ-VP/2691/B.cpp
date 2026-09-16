#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
int d[N];
int ori[N];
ll pre[N][N];
ll dp[25][N];
int from[25][N];
ll sum_d[N], sum_d2[N]; // 前缀和数组

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        d[i] = v[i - 1].first;
        ori[i] = v[i - 1].second;
    }

    for (int i = 1; i <= n; i++)
    {
        sum_d[i] = sum_d[i - 1] + d[i];
        sum_d2[i] = sum_d2[i - 1] + (ll)d[i] * d[i];
    }

    for (int j = 1; j <= n; j++)
    {
        pre[j][j] = 0;
        for (int i = j + 1; i <= n; i++)
        {
            ll count = i - j + 1;
            ll s1 = sum_d[i] - sum_d[j - 1];
            ll s2 = sum_d2[i] - sum_d2[j - 1];
            pre[j][i] = count * d[i] * d[i] - 2 * d[i] * s1 + s2;
        }
    }

    memset(dp, 0x3f, sizeof dp);

    // 初始化第1天
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = pre[1][j];
        from[1][j] = 0;
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int p = 1; p <= j; p++)
            {
                ll val = dp[i - 1][p] + pre[p + 1][j];
                if (val < dp[i][j])
                {
                    dp[i][j] = val;
                    from[i][j] = p; // 记录最优前驱
                }
            }
        }
    }

    vector<pair<int, int>> segments;
    int cur = n;
    for (int day = k; day >= 1; day--)
    {
        int p = from[day][cur];
        if (p == cur)
        {
            continue;
        }
        else
        {
            segments.push_back({p + 1, cur});
            cur = p;
        }
        if (cur == 0)
            break;
    }

    reverse(segments.begin(), segments.end());

    vector<int> ans(n + 1, 0);
    for (auto &seg : segments)
    {
        int l = seg.first, r = seg.second;
        int date = d[r]; // 这一段统一在 d[r] 交付
        for (int idx = l; idx <= r; idx++)
        {
            int orid = ori[idx];
            ans[orid] = date;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}