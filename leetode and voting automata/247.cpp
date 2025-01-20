#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<sstream>
using namespace std;

class Solution
{
public:
    unordered_set<char> ht;
    unordered_map<char, char> m;
    void setup_map(){
        m['1'] = '1';
        m['8'] = '8';
        m['0'] = '0';
        m['6'] = '9';
        m['9'] = '6';
        ht.insert('1');
        ht.insert('8');
        ht.insert('9');
        ht.insert('6');
        ht.insert('0');
    }
    bool is_strobogrammatic(int n){
        string s = to_string(n);
        for (int i = 0; i < s.size(); i++){
            if (!ht.count(s[i])){
                return false;
            }
        }
        string sr = stringReverse(s);
        for (int i = 0; i < s.size(); i++){
            if (m[s[i]] != sr[i]){
                return false;
            }
        }
        return true;
    }
    string stringReverse(string s){
        string retStr = "";
        
        while (s.size() != 0){
            retStr.push_back(s.back());
            s.pop_back();
        }
        return retStr;
    }
    vector<string> findStrobogrammatic(int n)
    {
        setup_map();
        vector <string> retVec;
        
        for (int i = pow(10, n - 1) - 1; i < pow(10, n); i++){
            if (is_strobogrammatic(i)){
                retVec.push_back(to_string(i));
            }
        }
        return retVec;
    }
};
int minPartitions(string n){
        int max = 0;
        for (int i = 0; n.size(); i++){
            if (static_cast<int>(n[i]) > max){
                max = static_cast<int>(n[i]);
            }
        }
        return max;
    }
int main(){
    // Solution s;
    // vector<string>v = s.findStrobogrammatic(8);
    // for (int i = 0; i < v.size(); i++){
    //     cout<<v[i]<<endl;
    // }
    cout<<minPartitions("32")<<endl;

}