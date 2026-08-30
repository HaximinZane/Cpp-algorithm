#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10, M = 1e3 + 10;

struct bar{
    int l,h;
};
unordered_map<int,bar> mp;

int up[N],down[N];
int dp[N][M];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        cin >> up[i] >> down[i];
    }
    for(int i = 1;i<=k;i++){
        int p,l,h;
        cin >> p >> l >> h;
        mp[p] = {l,h};
    }   

    memset(dp,0x3f,sizeof(dp));

    for(int j = 0;j<=m;j++) dp[0][j] = 0;
    
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        bool havbar = 0;
        int l = 0,h = m+1;
        if(mp.count(i)){
            l = mp[i].l;
            h = mp[i].h;
            havbar = 1;
        }

        for(int j = 1;j<=m;j++){
            if(j<=l || j >= h) continue;
            int lstu = up[i-1],lstd = down[i-1];
            if(j+lstd<=m) dp[i][j] = dp[i-1][j+lstd];
            if(j!=m){
                for(int t = 1;j-t*lstu >= 0;t++){
                    int lsth = j-t*lstu;
                    dp[i][j] = min(dp[i][j],dp[i-1][lsth]+t);
                }
            }
            else{
                dp[i][m] = min(dp[i][m],dp[i-1][m]+1);
                for(int z = 0;z<m;z++){
                    int ts = (m-z+lstu-1)/lstu;
                    dp[i][j] = min(dp[i][j],dp[i-1][z]+ts);
                }
            }
        }
        if(havbar){
            bool succ = 0;
            for(int j = 1;j<=m;j++){
                if(dp[i][j]<2e8){
                    succ = 1;
                    cnt++;
                    break;
                }
            }
            if(succ == 0){
                cout << 0 << '\n' << cnt;
                return 0;
            }
        }
    }

    int ans = 1e9;
    for(int j = 1;j<=m;j++){
        ans = min(ans,dp[n][j]);
    }
    cout << 1 << '\n' << ans;
}