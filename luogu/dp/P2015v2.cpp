#include<bits/stdc++.h>
using namespace std;

struct node{
    int s,val;
};
const int N = 105;
vector<node> g[N];
vector<node> tr[N];
int dp[N][N],vis[N];
int n, q;


int dfs(int i,int q){
    int res = 0;

    // 判断叶子节点
    if(tr[i].empty()) return dp[i][q] = 0;
    // 判断 q 是否为 0
    if(q==0) return dp[i][0] = 0;

    // 找到左右两个节点
    node l = tr[i][0],r = tr[i][1];

    // 先看全给一个节点的情况，有两种
    res = max(dfs(l.s,q-1)+l.val,dfs(r.s,q-1)+r.val);

    // 再看不同比例分配的情况
    for(int p = 1;p<q;p++){
        // p 表示给左节点分配p个，实际左节点自己可以分配的是p-1个
        // 那么右节点就是q-p个，可分配q-p-1个
        int lv,rv;
        if(dp[l.s][p-1] != -1) lv = dp[l.s][p-1] + l.val;
        else lv = dfs(l.s,p-1) + l.val;

        if (dp[r.s][q - p - 1] != -1)
            rv = dp[r.s][q - p - 1] + r.val;
        else
            rv = dfs(r.s, q - p - 1) + r.val;
        res = max(res,lv+rv);
    }
    return dp[i][q] = res;
}

int main(){
    cin >> n >> q;
    for(int i = 1;i<n;i++)
    {
        int a,b,v;
        cin >> a >> b >> v;
        g[a].push_back({b,v});
        g[b].push_back({a,v});
    }

    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        int cn = qu.front();
        vis[cn] = 1;
        qu.pop();
        for(auto x:g[cn]){
            if(vis[x.s]) continue;
            tr[cn].push_back(x);
            qu.push(x.s);
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(1,q) << endl;
}