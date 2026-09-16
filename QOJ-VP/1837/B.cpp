#include<bits/stdc++.h>
using namespace std;

vector<double> vec;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1>=0 && x2 >= 0) continue;
        if(x1<=0 && x2 <= 0) continue;
        if(x1==x2) continue;
        double t = (y1-y2)*x1/(x2-x1) + y1;
        if(t>0) vec.push_back(t);
    }
    if(vec.empty()){
        cout << -1 ;
        return 0;
    }
    sort(vec.begin(),vec.end());
    cout << vec[0];
}