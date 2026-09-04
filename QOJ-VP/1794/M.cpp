#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        unordered_map<string,vector<char>> mp;
        int n;
        cin >> n;
        while(n--){
            string t,res;
            char id;
            cin >> t >> id >> res;
            if(res[0] == 'a'){
                mp[t].push_back(id);
            }
        }
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(auto t : mp){
            sort(t.second.begin(),t.second.end());
            t.second.erase(unique(t.second.begin(),t.second.end()),t.second.end());

            for(auto c : t.second){
                arr[c-'A'] ++;
            }
        }
        int pos = 0;
        for(int i = 1;i<26;i++){
            if(arr[i] > arr[pos]) pos = i;
        }
        cout << (char)(pos + 'A') << '\n';
    }
}