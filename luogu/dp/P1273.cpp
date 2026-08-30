#include <bits/stdc++.h>
using namespace std;

struct son
{
    int node, w;
};

int n, m;
const int N = 3005;
int arr[N];
vector<son> g[N];
int dp[N][N];

void dfs(int x)
{
    if (g[x].empty())  // 说明 x 是观众节点，x > n-m
    {
        dp[x][0] = arr[x];
        return;
    }
    // 下面说明是转播节点
    // dp[i][j] 表示，在节点i已经选了的情况下，从节点i往下选，选j个叶子节点的利润
    // 从贪心角度来看，如果已知往下选0个叶子节点，那么就不应该再往下弄，因为只会增大花销
    dp[x][0] = 0;  // 所以设为0

    for (auto s : g[x]) dfs(s.node);


    for (auto s : g[x])
    {
        int nxt = s.node;  // 下一个节点
        int out = s.w;     // 选取下一个节点的花销
        for (int j = m; j >= 1; j--)
        {
            if (g[nxt].empty())  // 如果下一个节点是叶子节点
                // 如果选了，必须注意叶子节点最多提供 1 个 用户数量
                dp[x][j] = max(dp[x][j], dp[x][j - 1] + dp[nxt][0] - out);
            else
                for (int t = 1; t <= j; t++)
                    dp[x][j] = max(dp[x][j], dp[nxt][t] + dp[x][j - t] - out);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int t = 1; t <= k; t++)
        {
            int node, w;
            cin >> node >> w;
            g[i].push_back({node, w});
        }
    }
    for (int i = n - m + 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memset(dp,0xe0,sizeof(dp));
    dfs(1);
    for (int j = m; j >= 0; j--)
    {
        if(dp[1][j] >=0) {
            cout << j << '\n';
            return 0; 
        }
    }
}