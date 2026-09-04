```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long n,m;
        cin >> n >> m;
        vector<long long> w(n+1);

        for(long long i = 1;i<=n;i++)
            cin >> w[i];
        sort(w.begin()+1,w.end());
        
        // 找到最小的
        m-= w[1]*n;


        if(m<0){
            cout << "No" << '\n';
            continue;
        }
        if(m==0){
            cout << "YES" << '\n';
            continue;
        }

        vector<long long> dp(m + 1, 0x3f3f3f3f3f3f3f3f);
        dp[0] = 0;
        // 如果可以用 <= n 个物品凑出来，就可以
        // 相当于是，先用小的填，再用大的替换来增大重量
        // dp[i] 表示，重量为m的情况下，最少用的物品
        int k = w[1];
        for(long long i = 1;i<=n;i++){
            w[i] -= k;
            if(!w[i]) continue;
            for(long long j = w[i];j<=m;j++){
                dp[j] = min(dp[j],dp[j-w[i]] + 1);
            }
        }
        if(dp[m] <=n) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
```