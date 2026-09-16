#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long inf = 1e15;
const int N = 2e3+10;
struct datas
{
    int node;
    long long w;
};
vector<datas> g[N];
vector<long long> dis(N, inf);
int n, m;
void bf(int s){
    dis[s] = 0;
    for (int i = 1; i < n; i++)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (int)g[i].size(); j++)
            {
                datas curr = g[i][j];
                int cn = curr.node;
                long long cw = curr.w;
                if (dis[cn] > dis[i] + cw)
                {
                    flag = 0;
                    dis[cn] = dis[i] + cw;
                }
            }
        }
        if (flag)
            break;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    bf(1);
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == inf)
            cout << -1 << ' ';
        else
            cout << dis[i] << ' ';
    }
}