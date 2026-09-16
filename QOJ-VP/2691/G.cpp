#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
ll arr[N];
ll prefix[N];
int main(){
    ll r,n;
    cin >> r >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    int flag = 0;
    ll pos;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            ll t = prefix[i]-prefix[j];
            if(t >=  r){
                flag = 1;
                pos = i;
                break;
            }
            else if(t<=-r){
                flag = 2;
                pos = i;
                break;
            }
        }
        if(flag) break;
    }
    ll ans;
    if(!flag){
        cout << "uncertain";
        return 0;
    }
    else if(flag == 1) ans = r;
    else if(flag == 2) ans = 0; 
    for(int i = pos+1;i<=n;i++){
        if(ans+arr[i]>=r) ans = r;
        else if(ans+arr[i]<=0) ans = 0;
        else ans+=arr[i];
    }
    cout << ans;
}