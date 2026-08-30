#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int arr[N],v[N];
int n, w;
int cnt;
bool dfs(int i,int depth){
    if(i == n+1) return 1;
    if(cnt > depth) return 0;

    for(int l = 1;l<=min(i,depth);l++){
        if(v[l] + arr[i] > w) continue;
        else{
            if(v[l]==0){
                cnt++;
                v[l]+=arr[i];
                if(dfs(i+1,depth)) return 1;
                v[l]-=arr[i];
                cnt--;
            }
            else{
                v[l] += arr[i];
                if (dfs(i + 1, depth))
                    return 1;
                v[l] -= arr[i];
            }
        }
    }
    return 0;
}


int main(){

    cin >> n >> w;
    for(int i = 1;i<=n;i++) cin >> arr[i];

    for(int i = 1;i<=n;i++){
        cnt = 0;
        if(dfs(1,i)){
            cout << i;
            return 0;
        }
    }
}