#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int st[N];
int cnt[N];
int dist[N];
vector<int> topo;
queue<int> q;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int c;
        cin >> c;
        for(int j = 1;j<=c;j++){
            int p;
            cin >> p;
            g[i].push_back(p);
            cnt[p]++;
        }   
    }
    
    for(int i = 1;i<=n;i++){
        if(cnt[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int t = q.front();
        topo.push_back(t);
        q.pop();
        for(auto c:g[t]){
            cnt[c]--;
            if(cnt[c]==0) q.push(c);
        }
    }
    memset(dist,-1,sizeof(dist));
    dist[topo[0]] = 0;
    for(int i = 0;i<n;i++){
        int t = topo[i];
        if(dist[t]==-1) continue;
        for(auto j:g[t]){
            dist[j] = max(dist[j],dist[t]+1);
        }
    }


    for(int i = 1;i<=n;i++){
        if(dist[i]==n-1){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}