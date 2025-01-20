#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution
{
public:

    unordered_set<char> ht;
    unordered_map<char, char> m;
    vector <string> strobos;
    string c = "18096";

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

    bool is_strobogrammatic(string s){
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

        if (s.size() > 1){
            bool nonZero = false;
            for (int i = 0; i < s.size(); i++){
                if (s[i] != '0'){
                    nonZero = true;
                break;
                }   
            }
            return nonZero;
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

    void findStrobogrammaticHelper(int n, vector<int>& indexes, int i = 0){
        if (i == n){
            string s = "";
            for (int j = 0; j < indexes.size(); j++){
                s += c[indexes[j]];
            }
            if (is_strobogrammatic(s)){
                strobos.push_back(s);
            }
            return;
        }

        for (int val = 0; val < 5; val++){
            indexes[i] = val;
            findStrobogrammaticHelper(n, indexes, i + 1);
        }
    }
    static bool cmp(string& a, string& b){
        return(stoll(a) < stoll(b));
    }
    void killLeadingZeros(vector<string>& retVec){
        if (retVec[0][0] == '0' and retVec[0].size() != 1){
            retVec.erase(retVec.begin());
            killLeadingZeros(retVec);
        }
    }
    vector<string> findStrobogrammatic(int n)
    {
        setup_map();
        vector <string> retVec;
        vector <int> indexesVec;
        indexesVec.resize(n, 0);
        findStrobogrammaticHelper(n, indexesVec);
        
        for (auto& i : strobos){
            retVec.push_back(i);
        }
        sort(retVec.begin(), retVec.end(), cmp);
        killLeadingZeros(retVec);
        return retVec;
    }
};

int main(){
    Solution s;
    vector<string>v = s.findStrobogrammatic(14);
    cout<<"Done!\n";
}



class Solution {
public:
    int findCenter(vector<vector<int>>& edges){
        if (edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1]){
            return edges[0][0];
        }
        
        return edges[0][1];
    }
};