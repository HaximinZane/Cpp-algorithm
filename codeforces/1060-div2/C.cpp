#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maxVal = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            int b;
            cin >> b;
        }
        int limit = maxVal + 1;
        vector<int> st(limit + 1, 0), sp(limit + 1, 0);
        vector<int> primes;
        for (int i = 2; i <= limit; i++)
        {
            if (!st[i])
            {
                primes.push_back(i);
                sp[i] = i;
            }
            for (int j = 0; j < (int)primes.size(); j++)
            {
                int p = primes[j];
                if (1LL * p * i > limit)
                    break;
                st[p * i] = 1;
                sp[p * i] = p;
                if (i % p == 0)
                    break;
            }
        }
        unordered_map<int, int> mp;
        bool flag = false;
        auto process = [&](int x)
        {
            while (x > 1)
            {
                int prime = sp[x];
                if (prime == 0)
                { // 安全兜底，理论上不会触发
                    flag = true;
                    return;
                }
                mp[prime]++;
                if (mp[prime] > 1)
                {
                    flag = true;
                    return;
                }
                while (x % prime == 0)
                    x /= prime;
            }
        };
        for (int i = 1; i <= n; i++)
        {
            process(arr[i]);
            if (flag)
                break;
        }
        if (!flag)
        {
            for (int i = 1; i <= n; i++)
            {
                process(arr[i] + 1);
                if (flag)
                    break;
            }
        }
        if (flag)
            cout << 0 << "\n";
        else
            cout << 2 << "\n";
    }
    return 0;
}