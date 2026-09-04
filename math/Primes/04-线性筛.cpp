#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> st(n+1),prime;
    for(int i = 2;i<=n;i++){
        if(!st[i]) prime.push_back(i);
        for(int j = 0;prime[j]<=n/i;j++){
            st[prime[j]*i] = 1;

            // 这一步是重中之重，保证了prime[j] 一定是 prime[j] * i 这个数的最小质因子。
            if(i%prime[j]==0) break;
        }
    }
    // 和埃氏筛不同之处是，埃氏筛是遇到质数的时候开始筛，用的是，所有数都有质因子这个性质
    // 欧拉筛是，每个数都开始筛，但是只筛特定的一部分数，就是除以其最小质因子后为i的这些数
    for(auto x:prime) cout << x << ' ';
}