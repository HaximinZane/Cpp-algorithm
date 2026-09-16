#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int ga[N][N],gb[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> ga[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> gb[i][j];
        }
    }
    for(int t = 2;t<=n+m;t++){
        unordered_map<int,int> mp;
        for(int i = 1;i<=min(n,t-1);i++){
            int j = t-i;
            if(j>m) continue;
            int x = ga[i][j];
            mp[x]++;
        }
        for (int i = 1; i <= min(n,t - 1); i++)
        {
            int j = t - i;
            if(j>m) continue;
            int x = gb[i][j];
            if(mp[x]==0){
                cout << "NO";
                return 0;
            }
            mp[x]--;
        }
    }
    cout << "YES" ;
}