#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans = 1e9, tmp = 0;
const int N = 210;
int arr[N], dp[N];
bool flag = false;

void dfs(int i)
{ 
    if (tmp >= dp[i])
    {
        return;
    }
    dp[i] = tmp;
    if (i == b)
    {
        ans = tmp;
        flag = 1;
        return;
    }

    if(i+arr[i] <= n){
        tmp++;
        dfs(i + arr[i]);
        tmp--;
    }

    if(i-arr[i] > 0){
        tmp++;
        dfs(i - arr[i]);
        tmp--;
    }
}

int main()
{

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } 
    memset(dp,0x3f,sizeof(dp));
    dfs(a);
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}