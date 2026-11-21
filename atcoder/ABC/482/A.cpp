#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='o') cnt++;
    }
    if(cnt%2) cout << "odd";
    else cout << "even";
}