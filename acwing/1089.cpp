#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int arr[N];
int dp[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (i <= m)
            dp[i] = arr[i];
    }

    // 状态设计。dp[N]表示最后是N发的信号
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        while (i - dq.front() > m)
            dq.pop_front();
        if (i > m)
            dp[i] = dp[dq.front()] + arr[i];
        while (!dq.empty() && dp[dq.back()] >= dp[i])
            dq.pop_back();
        dq.push_back(i);
    }
    int ans = 1e9;
    for (int i = n; i > n - m; i--)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}