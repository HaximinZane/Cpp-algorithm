#include<bits/stdc++.h>
using namespace std;

struct datas{
    int y,t,v;
};
struct pos{
    int x,y;
};
struct node{
    int t,v;
};

map<pair<int,int>,vector<datas>> mp;
bool cmp(datas a,datas b){
    return a.y < b.y;
}
int gcd(int a,int b){
    a = abs(a);
    if(b==0) return a;
    return gcd(b,a%b);
}
int dp[205][40010];
vector<vector<node>> arr;
int main(){
    int n,T;
    cin >> n >> T;
    for(int i = 1;i<=n;i++){
        int x,y;
        int t,v;
        cin >> x >> y >> t >>v;
        int p = gcd(x,y);
        x/=p,y/=p;
        mp[{x,y}].push_back({y,t,v});
    }
    for(auto x:mp){
        sort(x.second.begin(),x.second.end(),cmp);
        vector<node> vec;
        int sumt = 0,sumv = 0;
        for(datas z:x.second){
            sumt += z.t,sumv += z.v;
            vec.push_back({sumt,sumv});
        }
        arr.push_back(vec);
    }
    int as = (int)arr.size();
    for(int i = 0;i<as;i++){
        for(int j = 0;j<(int)arr[i].size();j++){
            for(int t = T;t>=0;t--){
                dp[i+1][t] = dp[i][t];
                if(t >= arr[i][j].t){
                    dp[i+1][t] = max(dp[i+1][t],dp[i][t-arr[i][j].t] + arr[i][j].v);
                }
                
        }
    }
    cout << dp[as][T];
}