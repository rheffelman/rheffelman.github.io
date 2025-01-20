#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b){
    return a > b;
}
//--
void traverse(TreeNode * root){

    if (root->left){
        traverse(root->left);
    }
    if (root->right){
        traverse
    }
}
//--
int arrayOp(vector<int>v){
    if (!v.size()){
        return 0;
    }
    if (v.size() == 1){
        return v[0];
    }
    int sum = v[0];
    for (int i = 1; i < v.size(); i++){
        sum ^= v[i];
    }
    return sum;
}
//--
bool linearSearch(vector<int>v, int elem){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return true;
        }
    }
    return false;
}
//--
void parseIntoWords(string& s){
    string str = "";
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ' '){
            str += s[i];
        }
        else {
            v.push_back(str);
            str = "";
        }
    }
    v.push_back(str);
}
//--
string reverseStr(string& s){
    string retStr = "";
    for (int i = s.size() - 1; i >= 0; i--){
        retStr += s[i];
    }
    return retStr;
}
//--
string toMorse(string& s){
    const string ar[26] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string retStr = "";
    for (int i = 0; i < s.size(); i++){
        retStr += ar[int(s[i]) - 97];
    }
    return retStr;
}
//--
int pointDist(vector<int>&a, vector<int>& b){
    return sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2));
}
//--
string intToBinaryString(int x){
    string retStr = "";
    while (x > 1){
        retStr += to_string(x % 2);
        x /= 2;
    }
    string retStr2 = ""
    while (retStr.size()){
        retStr2 += retStr.back();
        retStr.pop_back();
    }
    return retStr2;
}