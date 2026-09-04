#include<bits/stdc++.h>
using namespace std;
vector<int> arr(33);
int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 1;i<=32;i++){
            cin >> arr[i];
        }
        int p = arr[1];
        sort(arr.begin()+1,arr.end(),greater<int>());
        int t;
        for(int i = 1;;i++){
            if(arr[i]==p){
                t = i;
                break;
            }
        }
        if(t==1) cout << 1;
        else if(t<=5) cout << 2;
        else if(t<=19) cout << 4;
        else if(t<=26) cout << 8;
        else if(t<=30) cout << 16;
        else cout << 32;
        cout << '\n';
    }
}