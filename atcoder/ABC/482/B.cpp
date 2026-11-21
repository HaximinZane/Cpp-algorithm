#include<bits/stdc++.h>
using namespace std;
int main(){
    string arr[6];
    for(int i = 1;i<=5;i++){
        cin >> arr[i];
    }
    int cnt = 5;
    for(int i = 1;i<=5;i++){
        int tmp = 0;
        for(int j = 0;j<5;j++){
            if(arr[i][j]=='o') tmp++;
        }
        cnt = min(cnt,5-tmp);
    }
    for(int j = 0;j<5;j++){
        int tmp = 0;
        for(int i = 1;i<=5;i++){
            if(arr[i][j]=='o') tmp++;
        }
        cnt = min(cnt,5 - tmp);
    }
    int tmp = 0;
    for(int i = 1;i<=5;i++){
        if(arr[i][i-1]=='o') tmp++;
    }
    cnt = min(cnt,5-tmp);
    cout << cnt;
}