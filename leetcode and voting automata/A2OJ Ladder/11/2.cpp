// https://codeforces.com/problemset/problem/263/A

#include<bits/stdc++.h>
using namespace std;


int x = 0;

void solve(){
    int i = 1;
    for(;x==0; i++){
        cin>>x;
    }
    int row = i/5;
    int col = 0;
    if (i%5 == 0) col = 5;
    else col = i%5;
    cout<<abs(3-col) + abs(3 - row);
}

int main(){
    solve();
}