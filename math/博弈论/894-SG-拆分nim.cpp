#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int arr[N],dp[N];


/*
    做这个题需要真正理解 SG 函数。
    记住！！！
    SG函数表示，目前的局面等效成一堆nim石子的个数，这是通过 mex 来实现的！
    所以，SG(A,B) = SG(A) ^ SG(B);
    其中A和B是两个独立子游戏！！！SG(A,B)表示A动B不动或者B动A不动后的mex
    在后继局面的时候，要用mex
    在独立局面的时候，要用异或！！！
*/
int sg(int a){
    if(dp[a]!=-1) return dp[a];
    unordered_set<int> st;
    for(int i = 0;i<a;i++){
        for(int j = 0;j<=i;j++){
            st.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0;;i++){
        if(!st.count(i))
            return dp[a] = i;
    }
}


int main(){
    int n;
    cin >> n;
    int x = 0;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        x ^= sg(arr[i]);
    }
    if(x) cout << "Yes";
    else cout << "No";
}