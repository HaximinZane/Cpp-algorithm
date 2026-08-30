#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sheep, wolves, pos;
};

int main()
{
    int a, b, p, q;
    cin >> a >> b >> p >> q;
    queue<node> qu;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(a + 1, vector<int>(b + 1, 1e9)));
    dp[0][a][b] = 0;
    qu.push({a, b, 0});
    while (qu.size())
    {
        auto [s, w, pos] = qu.front();
        qu.pop();

        if (s == 0 && pos == 1)
        {
            cout << dp[pos][s][w] << '\n';
            return 0;
        }

        for (int i = 0; i <= (pos == 0 ? s : a - s); i++)
        {
            for (int j = 0; j <= (pos == 0 ? w : b - w); j++)
            {
                if (i + j > p)
                    break;
                if (pos == 0 && s - i + q < w - j && s - i != 0)
                    continue;
                if (pos == 1 && a - s - i + q < b - w - j && a - s - i != 0)
                    continue;

                int na, nb;
                if (pos == 0)
                    na = s - i, nb = w - j;
                else
                    na = s + i, nb = w + j;

                if (dp[pos ^ 1][na][nb] > dp[pos][s][w] + 1)
                {
                    dp[pos ^ 1][na][nb] = dp[pos][s][w] + 1;
                    qu.push({na, nb, pos ^ 1});
                }
            }
        }
    }

    cout << -1 << '\n';
}

