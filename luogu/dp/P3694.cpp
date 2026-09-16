#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt[21];
int arr[N];
int dp[1 << 20];
int length[1 << 20];
int cost[N][21];

int lowbit(int m)
{
    return m & -m;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int p = cnt[i];
        length[1 << (i - 1)] = p;
    }
    for (int i = 1; i < (1 << m); i++)
    {
        int p = lowbit(i);
        length[i] = length[i - p] + length[p];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] == j)
                cost[i][j] = cost[i - 1][j];
            else
                cost[i][j] = cost[i - 1][j] + 1;
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << m); i++)
    {
        int r = length[i];
        for (int j = 1; j <= m; j++)
        {
            if ((1 << j - 1) > i)
                break;
            if (1 << j - 1 & i)
            {
                int lst = i - (1 << j - 1);
                int l = length[lst];
                dp[i] = min(dp[i], dp[lst] + cost[r][j] - cost[l][j]);
            }
        }
    }
    cout << dp[(1 << m) - 1];
}