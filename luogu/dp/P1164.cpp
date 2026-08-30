#include<bits/stdc++.h>
using namespace std;

const int M = 1e4 + 5,N = 105,INF = 1e9;
int dp[N][M],arr[N];
int main(){
    int n,m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            dp[i][w] += dp[i-1][w];
            if(w>=arr[i]) dp[i][w] += dp[i-1][w-arr[i]];
        }
    }
    cout << dp[n][m];
}