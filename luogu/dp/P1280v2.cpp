#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> g[N];
int dp[N];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=k;i++){
        int p,t;
        cin >> p >> t;
        g[p].push_back(t);
    }
    memset(dp,-1,sizeof(dp));
    
    dp[0] = 0,dp[1] = 0;
    for(int i = 1;i<=n;i++){
        if(dp[i] == -1) continue;
        if(g[i].empty()) dp[i+1] = max(dp[i+1],dp[i]+1);
        else{
            for(int x:g[i]){
                dp[i+x] = max(dp[i+x],dp[i]);
            }
        }
    }
    cout << dp[n+1];
}