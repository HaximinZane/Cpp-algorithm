#include<bits/stdc++.h>
using namespace std;

// 太考验思维了。。。。
// 只考虑奇数层的就可以，如果初始异或不是0，必输
// 因为nim，你可以调整奇数层，使得初始是0，后面你也可以一直维护
// 如果对方把偶数层的放到奇数层，我们就放到下一个偶数
// 如果对方奇数 -> 偶数，我们用nim的方式维护

int main(){
    int n;
    cin >> n;
    int x = 0;
    for(int i = 1;i<=n;i++){
        int a;
        cin >> a;
        if(i%2) x ^= a; 
    }
    if(x) cout << "Yes";
    else cout << "No";
}