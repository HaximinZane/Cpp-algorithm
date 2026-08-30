#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l,r;
};
node arr[20010];

bool cmp(const node &x, const node &y)
{
    // 1. 判断是否跨类别（一人 a <= b，另一人 a > b）
    if ((x.l <= x.r) && (y.l > y.r))
    {
        return true; // 左边属于第一/二类，右边属于第三类，左边必须排前面
    }
    if ((x.l > x.r) && (y.l <= y.r))
    {
        return false; // 左边属于第三类，右边属于第一/二类，左边不能排前面
    }

    // 2. 同属于第一/二类 (a <= b)：按 a 升序
    if (x.l <= x.r && y.l <= y.r)
    {
        return x.l < y.l;
    }

    // 3. 同属于第三类 (a > b)：按 b 降序
    return x.r > y.r;
}

int main(){
    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            long long l,r;
            cin >> l >> r;
            arr[i] = {l,r};
        }

        sort(arr+1,arr+n+1,cmp);

        long long c = arr[1].l+arr[1].r;
        long long pre = arr[1].l;
        for(int i = 2;i<=n;i++){
            pre += arr[i].l;
            c = max(c,pre) + arr[i].r;
        }
        cout << c << '\n';
    }
}