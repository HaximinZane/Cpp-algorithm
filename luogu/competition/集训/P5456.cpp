#include <iostream>
using namespace std;

const long long MOD = 2148473648ll; // 题目要求的取模数（务必加 ll 防止溢出）
long long ans[9];                   // 记录答案的数组，全局变量初始化为 0

// 乘法核心函数
void multiply(long long L)
{
    long long next_ans[9] = {0};

    // 构造这一维的多项式数组 P
    long long P[3] = {0};
    if (L == 1)
    {
        P[2] = 1;
    }
    else
    {
        P[0] = L - 2;
        P[1] = 2;
    }

    // 多项式相乘：ans(x) * P(x) -> next_ans(x)
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (i + j <= 8)
            {
                // 注意这里：系数相乘时可能非常大，必须在乘完后立刻取模
                // C++ 中取模律：(A + B*C) % M = (A % M + (B%M * C%M)%M) % M
                next_ans[i + j] = (next_ans[i + j] + (ans[i] % MOD) * (P[j] % MOD)) % MOD;
            }
        }
    }

    // 将结果更新回 ans 数组
    for (int i = 0; i <= 8; i++)
    {
        ans[i] = next_ans[i];
    }
}

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // 1. 初始化，相当于多项式最初是 1 * x^0
    for (int i = 0; i <= 8; i++)
    {
        ans[i] = 0;
    }
    ans[0] = 1;

    // 2. 依次把四个维度的多项式乘进去
    multiply(a);
    multiply(b);
    multiply(c);
    multiply(d);

    // 3. 输出结果，ans[0] 到 ans[8]
    for (int i = 0; i <= 8; i++)
    {
        cout << ans[i] << (i == 8 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}