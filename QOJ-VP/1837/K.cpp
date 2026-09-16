#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int ex[N],re[N],dp[N][N],s[N][N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> ex[i];
    }
    for(int i = 1;i<=m;i++){
        cin >> re[i];
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            int t = abs(re[i]-ex[j]);
            if(t <= 15) s[i][j] = 7;
            else if(t<=23) s[i][j] = 6;
            else if (t <= 43) s[i][j] = 4;
            else if (t <= 102) s[i][j] = 2;
        }
    }
    int ans = 0;
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j-1],dp[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s[i][j]);
        }
    }
    cout << dp[m][n];
}