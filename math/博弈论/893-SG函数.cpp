#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int p[N],arr[N],dp[10010];
int n, k;


// sg 函数，转化有限局面，利用mex和异或
int sg(int a){
    if(dp[a]!=-1) return dp[a];
    unordered_set<int> st;
    for(int i = 1;i<=k;i++){
        if(a>=p[i]) st.insert(sg(a-p[i]));
    }
    for(int i = 0;;i++){
        if(!st.count(i)) return dp[a] = i;
    }
}


int main(){

    cin >> k;
    for(int i = 1;i<=k;i++) cin >> p[i];
    cin >> n;

    memset(dp,-1,sizeof(dp));
    int x = 0;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        x ^= sg(arr[i]);
    }
    
    if(x) cout << "Yes";
    else cout << "No";


}