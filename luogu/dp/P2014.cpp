#include<bits/stdc++.h>
using namespace std;

struct node{
    int p,val;
};
const int N = 305;
int n,m;
vector<node> g[N];
int dp[N][N];

void dfs(int s,int val){
    dp[s][1] = val;
    if (g[s].empty())
        return;
    for (auto son : g[s])
    {
        int nxt = son.p, nval = son.val;
        dfs(nxt,nval);
    }

    for(auto son:g[s]){
        for(int i = m+1;i>1;i--){
            for(int j = 0;j<i;j++){
                dp[s][i] = max(dp[s][i],dp[son.p][j] + dp[s][i-j]);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        int k,s;
        cin >> k >> s;
        g[k].push_back({i,s});
    }
    dfs(0,0);
    cout << dp[0][m+1];
}










