#include<bits/stdc++.h>
using namespace std;


const int N = 55,M = 5e6 + 10;
pair<int,int> arr[N];
int dp1[M],dp2[M];
int main(){
    int n;
    cin >> n;
    int sum1,sum2;
    for(int i = 1;i<=n;i++){
        cin >> arr[i].first >> arr[i].second;
        sum1 += arr[i].first,sum2 += arr[i].second;
    }
    int up = max(sum1,sum2);
    for(int i = 1;i<=n;i++){
        for(int j = up;j>=0;j--){
            
        }
    }
}