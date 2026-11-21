#include<bits/stdc++.h>
using namespace std;

struct vec{
    int* a;
    size_t size_;
    vec() : a(new int[1]), size_(0) {};
    void insert(int x){
        a[size_++] = x;
    }
    int& operator[](size_t index){
        return a[index];
    }
    ~vec(){delete a;}
};

int main(){
    vec v;
    v.insert(1);
    v.insert(666);
    cout << v[1];
}