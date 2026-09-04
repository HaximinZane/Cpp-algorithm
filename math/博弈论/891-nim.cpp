#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int arr[N];

/*
    本题的核心在于 nim 游戏必胜和必败的推导
    给定 N 个数 a1 ~ an，记 X = 这N个数的异或
    有两个定理：
    1. 如果 X = 0，那么接下来减少 ai 任何一项，会让 X != 0
    2. 如果 X != 0，那么接下来一定有一种方法，可以让 X == 0
    方法是：找 X 最高位的 1，再找一个这一位也是 1 的 ak
    然后让 ak 变成 ak ^ X ，显然 ak 会减少(前面位数不变，有一位从1变成0) 
    这样再次异或就变成 X ^ X = 0 

    综上，是0的只能变成非0，非0的可以变成0，石子数不断减小，最终谁面临0谁输，也就是初始0输
*/

int main(){
    int n;
    cin >> n;
    int x = 0;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        x ^= arr[i];
    }

    if(!x) cout << "No";
    else cout << "Yes";


}