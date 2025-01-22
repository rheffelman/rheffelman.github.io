#include <bits/stdc++.h>
using namespace std;
    int toInt(string& s){
        int ret = 0;
        for (int i = 0; i < s.size() - 1; i++){
            ret +=  (s[i] - '0') * pow(10, s.size() - (i + 1));
        }
        ret += s[s.size() - 1] - '0';
        return ret;
    }
    int reverse(int x){
        string y = to_string(x);
        string y2 = "";
        cout<<y<<endl;
        while(y.size()){
            y2.push_back(y.back());
            y.pop_back();
        }
        int d = stoi(y2);
        if (d >= INT_MAX or d <= INT_MIN){
            return 0;
        }
        // if (x<0){
        //     d *= -1;
        // }
        return d;
    }
    int findComplement(int num){
        return static_cast<unsigned int>(~num);
    }
int main(){

    // array of ducks
    string ducks[5] = {"duck0", "duck12", "duck123", "duck1234", "duck1234sdjfg;lsjhdfgpiowehrtg pnwedm,f.gnw;eoklirhgtpoiwqerng;lwsdfkgmnw;peorhg5"};
    int ar[5] = {2, 3, 5, 7, 11};
    // print a duck
    std::cout << sizeof(bool);


}