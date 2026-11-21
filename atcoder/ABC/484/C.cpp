#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int arr1[N],arr2[N],arr3[N],arr4[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr2[i];
    }

    int i = 1;
    while(i <= n && arr1[i]==arr2[i]){
        i++;
    }
    if(i==n+1){
        cout << "Yes";
        return 0;
    }
    int j = n;
    while(j>=1 && arr1[j]==arr2[j]){
        j--;
    }
    if(i==j){
        cout << "No";
        return 0;
    }



    for(int st = i;st<j;st++)
        arr3[st] = arr1[st+1];
    arr3[j] = arr1[i];
    
    for(int st = j;st>i;st--){
        arr4[st] = arr1[st-1];
    }
    arr4[i] = arr1[j];

    bool flag1 = 1,flag2 = 1;
    for(int st = i;st<=j;st++){
        if(arr3[st]!=arr2[st]){
            flag1 = 0;
            break;
        }
    }

    for (int st = i; st <= j; st++)
    {
        if (arr4[st] != arr2[st])
        {
            flag2 = 0;
            break;
        }
    }

    if(flag1 || flag2){
        cout << "Yes";
        return 0;
    }

    cout << "No";

}



/*

aaabcdddd
abaacdddd


*/