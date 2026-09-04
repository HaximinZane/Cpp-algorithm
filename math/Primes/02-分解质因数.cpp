#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> p;
    for(int i = 2;i<=n/i;i++){
        while(n%i==0){
            p.push_back(i);
            n /= i;
        }
        if(n == 1) break;
    }
    if(n!=1) p.push_back(n);

    for(auto x:p) cout << x << ' ';
}