#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, t1, t2;
    s1 = "0", s2 = "0";
    cin >> t1 >> t2;
    s1 += t1, s2 += t2;

    int l1 = (int)s1.size();
    int l2 = (int)s2.size();

    vector<int> ne(l2);
    ne[1] = 0;
    for (int i = 2, j = 0; i < l2; i++)
    {
        while (j != 0 && s2[i] != s2[j + 1])
            j = ne[j];
        if (s2[i] == s2[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i < l1; i++)
    {
        while (j && s1[i] != s2[j + 1])
            j = ne[j];
        if (s1[i] == s2[j + 1])
            j++;
        if (j == l2 - 1)
            cout << i - j + 1 << '\n';
    }
    for (int i = 1; i < l2; i++)
        cout << ne[i] << ' ';
}