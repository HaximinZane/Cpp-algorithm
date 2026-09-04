#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,long long> mp;
const long long mod = 1000000007;
void solve(long long a){
    for(long long i = 2;i<=a/i;i++){
        while(a%i==0){
            mp[i]++;
            a/=i;
        }
    }
    if(a!=1) mp[a]++;
}


int main(){
    long long n;
    cin >> n;
    for(long long i = 1;i<=n;i++){
        long long a;
        cin >> a;
        solve(a);
    }
    
    long long ans = 1;
    for(auto x:mp){
        cout << x.first << ' ' << x.second << '\n';
        ans = ans % mod * (x.second + 1) % mod;
        ans %= mod;
    }
    cout << ans;
}