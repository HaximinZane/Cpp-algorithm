#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> st(n+1),euler(n+1),prime;
    /*
    
    st记录这个数是否被标记过，prime记录是否是质数，euler记录欧拉函数值
    关键还是在那个欧拉函数的计算公式，然后递推
    但是要注意一个点，可以往后推的前提是当前的算过。那是自然，当前的已经被前面筛过了。
    如果没筛过说明是素数，那么循环前已处理
    
    */


    euler[0] = 0,euler[1] = 1;
    for(int i = 2;i<=n;i++){
        if(!st[i]){
            euler[i] = i-1;
            prime.push_back(i);
        }
        for(int j = 0;prime[j]<=n/i;j++){
            int p = prime[j];
            st[i * p] = 1;
            if(i % p != 0)
                euler[i*p] = (p-1)*euler[i];
            else{
                euler[i*p] = p*euler[i];
                break;
            }
        }
    }

    long long res = 0;
    for(int i = 1;i<=n;i++){
        res += euler[i];
    }
    cout << res;
}