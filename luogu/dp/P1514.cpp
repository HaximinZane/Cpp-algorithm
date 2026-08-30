#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y;
};
int n, m;
const int N = 505;
int mp[N][N], vis[N][N], bound[N][N][2];
node dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].x, ny = y + dir[i].y;
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] < mp[x][y])
        {
            if (!vis[nx][ny])
                dfs(nx, ny);
            bound[x][y][0] = min(bound[x][y][0], bound[nx][ny][0]);
            bound[x][y][1] = max(bound[x][y][1], bound[nx][ny][1]);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bound[i][j][0] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        bound[n][i][0] = i, bound[n][i][1] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (!vis[1][i])
            dfs(1, i);
    }

    bool cando = 1;
    int nans = 0, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[n][i])
        {
            cando = 0;
            nans++;
        }
    }
    if (!cando)
    {
        cout << 0 << '\n'
             << nans;
        return 0;
    }
    int pos = 0;
    int t = 1;

    while (t <= m)
    {
        while (bound[1][t][0] == 1e9)
            t++;
        int p = t + 1;
        while (bound[1][p][0] == 1e9)
            p++;
        if (p <= m && bound[1][p][0] <= pos + 1)
        {
            t = p;
            continue;
        }
        if (p > m)
        {
            if (pos == m)
                break;
        }
        pos = bound[1][t][1];
        ans++;
        t = p;
    }

    cout << 1 << '\n'
         << ans;
}