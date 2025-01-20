#include<bits/stdc++.h>
using namespace std;



bool hasDistinctDigits(int y){
    string s = to_string(y);
    unordered_set<char> ht;
    for (int i = 0; i < s.size(); i++) ht.insert(s[i]);
    return (ht.size() == s.size());
}

int in;
void solve(){
    cin>>in;
    in++;
    while (!hasDistinctDigits(in)){
        in++;
    }
    cout<<in;
}

int main(){
    solve();
}