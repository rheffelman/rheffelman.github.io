#include<bits/stdc++.h>
using namespace std;


string in = "";

void solve(){
    cin>>in;
    string retStr = "";
    int i = 0;
    for (;i < in.size();){
        if (in[i] == '.'){
            retStr += "0";
            i++;
        }
        else if (in[i] == '-'){
            if (in[i + 1] == '-'){
                retStr += "2";
                i += 2;
            }
            else{
                retStr += "1";
                i += 2;
            }
        }
    }
    cout<<retStr;
}

int main(){
    solve();
}