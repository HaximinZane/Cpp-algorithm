#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr;
int dp[40005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, wmax;
    cin >> n >> wmax;
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        cin >> v >> w >> m;
        int t = 1;
        while (1)
        {
            if (m <= t)
            {
                arr.push_back({v * m, w * m});
                break;
            }
            else
            {
                arr.push_back({v * t, w * t});
                m -= t;
                t *= 2;
            }
        }
    }
    int cnt = (int)arr.size();
    for (int g = 0; g < cnt; g++)
    {
        int wg = arr[g].second, wv = arr[g].first;
        for (int w = wmax; w > 0; w--)
        {

            if (w >= wg)
                dp[w] = max(dp[w], dp[w - wg] + wv);
        }
    }
    cout << dp[wmax] << endl;
}