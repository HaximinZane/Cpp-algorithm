#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
using ll = long long;


ll arr[N];


int main(){
    ll t;
    cin >> t;
    // t是数据组数
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> arr[i];
        }
        // 以上是处理输入

        ll ans = 0;
        stack<int> s;
        for(int i = 1;i<=n;i++){
            // 维护一个单调递减栈
            while(!s.empty() && arr[s.top()] < arr[i]){
                s.pop();
                int pos;
                if(s.empty()) pos = 0; 
                else pos = s.top();
                ans += i - pos - 1;
                // 接雨水模板
            }
            while (!s.empty() && arr[s.top()] == arr[i])
                s.pop();
            // 特殊之处，相同的话左边的都要出栈
            s.push(i);
        }

        // 下面是比接雨水多的东西，就是处理栈里的残余
        // 首先，上面循环里，不管怎么样我最后都有push
        // 所以p可以直接取
        int p = s.top();
        s.pop();
        // 如果还有残余，会依次由小到大进行操作
        while(!s.empty()){
            int t = s.top();
            s.pop();
            ans += p-t;
        }
        // 输出
        cout << ans << '\n';
    }
}