#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int mid = (n+1)/2;
    int ans = 0;

    if(k==1 || k==n){
        cout << n*3;
        return 0;
    }
    if(k<=mid){
        ans += n*3;
        ans += k-1;
    }
    else{
        ans += n*3;
        ans += n-k;
    }
    cout << ans;
}