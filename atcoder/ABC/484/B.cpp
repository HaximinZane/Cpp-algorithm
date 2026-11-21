#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int minp = 10;
    bool flag = 1;
    int k;
    for(int i = 1;i<=n;i++){
        cin >> k;
        minp =  min(minp,k);
        if(k==9) flag = 0;
    }
    if(flag) cout << -1;
    else
    cout << minp;
    
}