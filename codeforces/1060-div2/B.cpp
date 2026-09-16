#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+10;

int arr[N];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> arr[i];
        }
        int lmax = arr[1];
        ll ans = 0;
        for(int i = 2;i<=n;i++){
            lmax = max(lmax,arr[i]);
            if(i%2==0) arr[i] = lmax;
        }
        for(int i = 2;i<=n;i++){
            if(i%2==0){
                if(arr[i]<=arr[i-1]){
                    ans++;
                }
            }
            if(i%2){
                if(arr[i]>=arr[i-1]){
                    ans+=arr[i]-arr[i-1]+1;
                    arr[i] = arr[i-1] - 1;
                }
            }
        }
        cout <<  ans << '\n';
    }
}