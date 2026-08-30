#include <bits/stdc++.h>
using namespace std;

int n;
int mp[9][9]; 
int dp[9][9][9][9][18];
int sum[9][9];


int get_sum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int dfs(int x1, int y1, int x2, int y2, int k)
{
    if (k == 1)
    {
        int s = get_sum(x1, y1, x2, y2);
        return dp[x1][y1][x2][y2][1] = s * s;
    }

    if (dp[x1][y1][x2][y2][k] != -1)
        return dp[x1][y1][x2][y2][k];

    int res = 1e9;


    for (int i = x1; i < x2; i++)
    {
        int t1 = dfs(x1, y1, i, y2, k - 1);
        int s1 = get_sum(i + 1, y1, x2, y2);

        int t2 = dfs(i + 1, y1, x2, y2, k - 1);
        int s2 = get_sum(x1, y1, i, y2);

        res = min({res, t1 + s1 * s1, t2 + s2 * s2});
    }

    for (int j = y1; j < y2; j++)
    {
        int t1 = dfs(x1, y1, x2, j, k - 1);
        int s1 = get_sum(x1, j + 1, x2, y2); 

        int t2 = dfs(x1, j + 1, x2, y2, k - 1);
        int s2 = get_sum(x1, y1, x2, j);

        res = min({res, t1 + s1 * s1, t2 + s2 * s2});
    }

    return dp[x1][y1][x2][y2][k] = res;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> mp[i][j];
            sum[i][j] = mp[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }


    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 1, 8, 8, n) << endl;

    return 0;
}