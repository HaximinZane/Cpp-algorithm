#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int ed[N],dp[N];
unordered_map<int,vector<int>> mp;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=k;i++){
        int s,t;
        cin >> s >> t;
        ed[i] = s + t;
        mp[s].push_back(i);
        // key : start-time   val: node
    }

    for(int i = n;i>=1;i--){
        if(mp.count(i)){
            for(auto x : mp[i]){
                dp[i] = max(dp[i],dp[ed[x]]);
            }
        }
        else dp[i] = dp[i+1] + 1;
    }

    cout << dp[1];
}