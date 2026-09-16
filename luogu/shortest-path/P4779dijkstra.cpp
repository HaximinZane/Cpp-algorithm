#include<bits/stdc++.h>
using namespace std;
const int inf = 2e9,N = 1e5+10;
struct datas{
    int node, w;
    bool operator< (const datas &other) const {
        return w > other.w;
    }
};
int n, m, s;

bool vis[N];
int dis[N];
vector<datas> mp[N];
void dijkstra(int i){
    priority_queue<datas> prq;

    dis[i] = 0;
    prq.push({i, 0});
    while (!prq.empty())
    {
        datas curr = prq.top();
        prq.pop();
        int cn = curr.node;
        if (vis[cn])
            continue;
        dis[cn] = curr.w;
        vis[cn] = 1;
        for (int i = 0; i < (int)mp[cn].size(); i++)
        {
            prq.push({mp[cn][i].node, mp[cn][i].w + dis[cn]});
        }
    }
}
int main(){

    cin >> n >> m >> s;

    for (int i = 1; i <= m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
    }
    memset(dis,0x3f,sizeof(dis));
    dijkstra(1);
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
}