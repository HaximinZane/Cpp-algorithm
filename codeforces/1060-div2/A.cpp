#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i]=='1'){
                if(sum==0) ans++;
            }
            sum+=(int)(s[i]-'0');
            if(i>=k-1) sum -= (int)(s[i-k+1]-'0');

        }
        cout << ans << '\n';
    }




}