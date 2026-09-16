#include<bits/stdc++.h>
using namespace std;
const int N = 35;
vector<string> mp;
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};
int cnt[N][N],st[N][N];
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        mp.push_back(s);
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){

            char c = mp[i][j];
            if(c=='?'){
                // 照亮空地
                // 上下左右的顺序
                for(int t = i-1;t>=0;t--){
                    if(mp[t][j]=='.') st[t][j]=1;
                    else if(mp[t][j]=='?'){
                        cout << 0;
                        return 0;
                    }
                    else break;
                }
                for (int t = i + 1; t < n; t++)
                {
                    if (mp[t][j] == '.')
                        st[t][j] = 1;
                    else if (mp[t][j] == '?')
                    {
                        cout << 0;
                        return 0;
                    }
                    else
                        break;
                }
                for (int t = j - 1; t >= 0; t--)
                {

                    if (mp[i][t] == '.')
                        st[i][t] = 1;
                    else if (mp[i][t] == '?')
                    {
                        cout << 0;
                        return 0;
                    }
                    else
                        break;
                }
                for (int t = j + 1; t < n; t++)
                {
                    if (mp[i][t] == '.')
                        st[i][t] = 1;
                    else if (mp[i][t] == '?')
                    {
                        cout << 0;
                        return 0;
                    }
                    else
                        break;
                }

                for(int d = 0;d<4;d++){
                    int nx = i+x[d],ny = j+y[d];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        cnt[nx][ny]++;
                    }
                }
            }

        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            char c = mp[i][j];
            if(c=='.'){
                if(st[i][j]==0){
                    cout << 0;
                    return 0;
                }
            }
            else if(c=='X' || c=='?') continue;
            else{
                int t = c - '0';
                if(cnt[i][j]!=t){
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << 1;
}