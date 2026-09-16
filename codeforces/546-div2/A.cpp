#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        for(int j = l;j<=r;j++) arr[j] = i;
    }
    int k;
    cin >> k;
    cout << n - arr[k]+1;
}