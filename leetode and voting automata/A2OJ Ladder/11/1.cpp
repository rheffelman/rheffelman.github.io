// https://codeforces.com/problemset/problem/69/A

#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int n, x, y, z;

void solve(){

    valarray<double> v;
    v.resize(3, 0);

    cin >> n;
    bool a = 1;

    for (int i = 0; i < n; i++){
        cin >> x >> y >> z;
        v[0] += x;
        v[1] += y;
        v[2] += z;
    }

    for (int i = 0; i < 3; i++){
        if (v[i]) a = 0;
    }

    if (a) cout<<"YES";
    else cout<<"NO";
}

int main(){
    solve();

}