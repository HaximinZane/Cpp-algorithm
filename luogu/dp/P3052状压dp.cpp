#include<bits/stdc++.h>
using namespace std;
struct datas{
    int cnt,vol;
};
datas dp[1<<18];
int arr[20];
int main(){
    int n,w;
    cin >> n >> w;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int m = 0;m<(1<<n);m++)
        dp[m].cnt = 1e9,dp[m].vol = 0;
    // dp[i][mask] 意思是 用了 i 个电梯，装了mask情况下的人
    dp[0].cnt = 1;
    for(int m = 0;m<(1<<n);m++){
        for(int i = 0;i<n;i++){
            if((1<<i & m) == 0){
                int nxtcnt = dp[m].cnt,nxtvol = dp[m].vol,nxtm = m | (1<<i);
                if(arr[i] + dp[m].vol <= w){
                    nxtvol += arr[i];
                }
                else{
                    nxtcnt++;
                    nxtvol = arr[i];
                }
                if(dp[nxtm].cnt > nxtcnt || (dp[nxtm].cnt==nxtcnt && dp[nxtm].vol>nxtvol)) dp[nxtm] = {nxtcnt,nxtvol};
            }
        }
    }

    cout << dp[(1<<n)-1].cnt;
}