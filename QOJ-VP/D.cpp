/*

题目要求：
有一 0 1 字符串 s1~sn，
定义 pi 为 s1~si 中与si不同的字符的个数。
现给定一个可重集合A, |A| = n
表示 p1~pn 的所有取值

问有多少种字符串可以满足 A 的约束

*/

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> p;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        // 这里输入的是pi那个集合
        int a;
        cin >> a;
        p[a]++;
    }
    int ans = 1,cnt0 = 0,cnt1 = 0;
    // cnt0 记录 i 之前 0 的个数，cnt1 记录 i 之前 1 的个数
    for(int i = 1;i<=n;i++){
        // 我们去看每一个位置应该放哪些p
        // 通过这个来看si放0还是1
        // 由于题目保证一定有解，方便很多

        if(cnt0==cnt1){
            // ans*2 消除了对称性，我们就优先放1（无所谓）
            // 由于这个策略，我们不可能让cnt0 > cnt1
            ans*=2;
            p[cnt1]--;
            cnt1++;
        }
        else{
            /*
                cnt0 < cnt1 时
                首先这里的 p 取值只能放 cnt0 或者 cnt1
                先看看有没有 cnt0 这个 p，因为cnt0较小
                如果有的话，
                假如我们不放这个 cnt0 的 p
                而是放值为 cnt1 的 p，那么相当于放了一个 si = 0，
                此时 cnt0++
                原来那个值为 cnt0 的 p 就不可能再用上（因为此时 cnt0 和 cnt1 都比这个 p 大），
                而这是不可能的，因为题目保证有解
                所以如果有 p = cnt0 的话，这是必选的
            */
            // 所以下面都是一本道，必须这么做。于是不会导致 ans 增加
            if(p[cnt0]){
                p[cnt0]--;
                cnt1++;
            } 
            
            // 如果没有 p = cnt0 ，那也没办法，那就肯定有p = cnt1，放上去即可
            else{
                p[cnt1]--;
                cnt0++;
            }
        }
    }
    cout << ans << endl;
}