#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

核心是要记住欧拉函数的计算方法和概念
给定一个 N，求 1 ~ N 中与 N 互质的数的个数
计算方法， = N * (1-1/p1) * ... * (1-1/pn)
证明方法：容斥原理，减去所有pi的倍数，减多了加，加多了减

*/


ll solve(int a){
    ll res = a;
    for(int i = 2;i<=a/i;i++){
        if(a%i!=0) continue;
        while(a%i==0){
            a /= i;
        }
        res /= i ;
        res *=  (i-1);
    }
    if(a!=1) res = res / a * (a-1);

    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        cout << solve(a) << '\n';
    }
}