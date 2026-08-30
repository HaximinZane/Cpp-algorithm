#include<bits/stdc++.h>
using namespace std;
int main(){
    long long T;
    cin >> T;
    while(T--){
        long long n,k;
        cin >> n >> k;
        vector<long long> a(n);
        bool h1 = 0;
        for(long long i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]==1) h1 = 1;
        }
        if(k==1){
            if(h1)cout << -1 <<'\n';
            else cout << 0 << '\n';
            continue;
        }

        vector<long long> need(k);
        priority_queue<long long,vector<long long>,greater<long long>> prq;
        for(long long x:a){
            if(x<k){
                if(need[x]) prq.push(x);
                else need[x] = 1;
            }
            else prq.push(x);
        }
        long long res = 0,flag = 0;
        for(long long i = 1;i<k;i++){
            if(need[i] == 0){
                while(!prq.empty() && prq.top() < i ) prq.pop();
                if (prq.empty()){
                    cout << -1 << '\n';
                    flag = 1;
                    break;
                }
                res += prq.top() - i;
                prq.pop();
            }
        }
        if(flag) continue;
        while(!prq.empty() && prq.top()<k) prq.pop();
        long long cnt = 0;
        while(!prq.empty() && prq.top()==k){
            prq.pop();
            cnt++;
        }
        cout << res + cnt << '\n';
    }
}