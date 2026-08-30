#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int main()
{
    string s, t;
    cin >> s >> t;
    int l1 = (int)s.size(), l2 = (int)t.size();
    for (int i = 1; i <= l1; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= l2; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            if (s[i - 1] == t[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    cout << dp[l1][l2] << endl;
}