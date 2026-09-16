#include<bits/stdc++.h>
using namespace std;
int arr[55];
int st[55];
vector<int> ans;
int main(){
    int n;
    cin >> n;
    int k = n + n;
    n *= 10;
    for(int i = 1;i<=5*n;i++){
        int t;
        cin >> t;
        arr[t]++;
        if(arr[t]>k && st[t] == 0){
            ans.push_back(t);
            st[t] = 1;
            
        }
    }
    if(!ans.empty()){
        sort(ans.begin(),ans.end());
        for(int x:ans) cout << x <<' ';
    }
    else cout << -1 ;
}