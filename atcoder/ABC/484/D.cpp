#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int arr[N],cnt[N],rcnt[N],dp[N];


int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n ;i++){
        cin >> arr[i];
    }

    rcnt[arr[1]]++;
    for(int i = 2;i<=n;i++){
        if(arr[i]==arr[i-1]){
            rcnt[arr[i]]++;
            continue;
        }
        else{
            dp[i] = i-1;
            cnt[i] = rcnt[arr[i]];
        }
        rcnt[arr[i]]++;

    }

    long long ans = 0;
    for(int i = 1;i<=n;i++){
        ans += dp[i];
        ans -= cnt[i];
    }

    cout << ans + 1;
}