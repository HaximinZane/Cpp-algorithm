#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll p[20];

int main(){
    ll n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++) cin >> p[i];

    int ans = 0;
    for(int i = 1;i < (1<<m) ;i++){
        ll cnt = 0,tmp = 1;
        for(int j = 0;j<m;j++){
            if((i>>j) & 1){
                if(tmp * p[j] > n){
                    tmp = 0;
                    break;
                }
                tmp *= p[j];
                cnt++;
            }
        }
        if(tmp){
            if(cnt%2) ans += n/tmp;
            else ans -= n/tmp;
        }
    }
    cout << ans;

}