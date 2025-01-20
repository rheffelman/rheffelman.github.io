#include<bits/stdc++.h>
using namespace std;


int n, t;
string line;

void solve(){
    cin>>n>>t>>line;
    for (int i = 0; i < t; i++){
        int j = 0;
        for(;j < n;){
            if (line[j] == 'B' and line[j + 1] == 'G'){
                char c = line[j];
                line[j] = line[j + 1];
                line[j + 1] = c;
                j++;
            }
            j++;
        }
    }
    cout<<line;
}

int main(){
    solve();
}