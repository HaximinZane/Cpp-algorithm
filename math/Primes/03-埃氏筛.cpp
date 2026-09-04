#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> st(n+1),prime;
    for(int i = 2;i<=n;i++){
        // 核心思想是，找到质数开始筛，下一个数肯定是与他互质的数，且一定也是质数
        if(!st[i]){
            prime.push_back(i);
            for(int j = i;j<=n/i;j++){
                // 筛的方式挺朴素的，就是从自己筛到n，但是好像可以从i*i开始筛？
                st[j*i] = 1;
            }
        }
    }
    for(auto x:prime) cout << x << ' ';
}