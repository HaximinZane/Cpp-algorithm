#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        string s;
        cin >> s;
        mp[s]++;
    }
    string ans;
    int x = 0;
    for(auto p:mp){
        if(p.second>x){
            ans = p.first;
            x = p.second;
        }
    }
    cout << ans;
}