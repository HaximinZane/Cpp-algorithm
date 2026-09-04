#include<bits/stdc++.h>
using namespace std;

// 核心公式在于：Ca,b = Ca-1,b + Ca-1,b-1;
// 计算的时候递推即可，能处理 a*b <= 1e8 的全部组合数
// 复杂度就是 a*b 后面的询问都是 O(1)
const int N = 2005,mod = 1e9 + 7;
int C[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<=2000;i++) C[i][0] = 1;
    for(int a = 1;a<=2000;a++){
        for(int b = 1;b <= a;b++){
            if(a==b) C[a][b] = 1;
            else{
                C[a][b] = (C[a-1][b-1] + C[a-1][b]) % mod;
            }
        }
    }
    while(n--){
        int a,b;
        cin >> a >> b;
        cout << C[a][b] << '\n';
    }
}