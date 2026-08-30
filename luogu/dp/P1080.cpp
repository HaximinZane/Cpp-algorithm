#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct d
{
    int l, r;
};
d arr[N];

// 贪心策略：按左右手乘积从小到大排序
bool cmp_struct(d a, d b)
{
    return a.l * a.r < b.l * b.r;
}

// 1. 高精度乘法（高精乘低精）
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0; // 进位
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    // 去除前导0（虽然乘法一般不会产生，但好习惯）
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

// 2. 高精度除法（高精除低精）
vector<int> div(vector<int> &A, int b)
{
    vector<int> C;
    long long r = 0; // 余数
    // 除法从最高位开始算
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    // 反转过来变成低位在前面
    reverse(C.begin(), C.end());
    // 去除前导0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

// 3. 高精度比较大小
bool cmp_max(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() < B.size(); // 位数不同，位数多的更大
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] < B[i]; // 从最高位开始比
    }
    return false; // 相等
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i].l >> arr[i].r;
    }

    // 只有大臣参与排序，国王在 arr[0] 不动
    sort(arr + 1, arr + n + 1, cmp_struct);

    vector<int> current_mul; // 维护前面所有人的左手乘积
    // 初始化为国王的左手
    int temp = arr[0].l;
    while (temp)
    {
        current_mul.push_back(temp % 10);
        temp /= 10;
    }

    vector<int> ans;
    ans.push_back(0); // 初始化答案为 0

    for (int i = 1; i <= n; i++)
    {
        // 计算当前大臣的奖赏：前面所有的左手乘积 / 当前右手数
        vector<int> current_reward = div(current_mul, arr[i].r);

        // 更新最大值
        if (cmp_max(ans, current_reward))
        {
            ans = current_reward;
        }

        // 更新前缀乘积
        current_mul = mul(current_mul, arr[i].l);
    }

    // 输出答案（倒序输出，因为最高位在最后）
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}