#include "Solution.h"

//  Problem 1720
vector<int> Solution::decode(vector<int>& encoded, int first){
    vector <int> decoded;
    decoded.push_back(first);

    for (int i = 0; i < encoded.size(); i++){
        decoded.push_back(encoded[i] ^ decoded[i]);
    }
    return decoded;
}
//--
//  Problem #1486
int Solution::xorOperation(int n, int start){
    if (n > 1){
        int y = start ^ start + 2;

        for (int i = 2; i < n; i++){
            y = y ^ (start + (2 * i));
        }
        return y;
    }
    else return start;
}
//--
//  Problem #1342
int Solution::numberOfSteps(int num){
    int count = 0;

    for (;num != 0;){
        count++;
        if (num % 2 == 0){
            num /= 2;
        }
        else{
            num -= 1;
        }
    }
    return count;
}
//--
//  Problem #2220
int Solution::minBitFlips(int start, int goal){
    bitset<60> a(start);
    bitset<60> b(goal);
    int count = 0;

    for (int i = 0; i < 60; i++){
        if (a[i] == b[i]) continue;
        else count++;
    }  
    return count;
}
//--
//  Problem #1684
int Solution::countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set <char> alwd;
    int count = 0;

    for (int i = 0; i < allowed.length(); i++){
        alwd.insert(allowed[i]);
    }
    
    for (int i = 0; i < words.size(); i++){
        for (int j = 0; j < words[i].length(); j++){
            if (!alwd.count(words[i][j])) break;
            if (j == words[i].length() - 1) count++;
        }
    }
    return count;
}
//--
//  Problem #832
vector<vector<int>> Solution::flipAndInvertImage(vector<vector<int>>& image){
    vector<vector<int>> v;
    v.resize(image.size());

    for (int i = 0; i < image.size(); i++){
        for (int j = image[i].size() - 1; j >= 0; j--){
            v[i].push_back(image[i][j]);
        }
    }

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            if (v[i][j]) v[i][j] = 0;
            else v[i][j] = 1;
        }
    }
    return v;
}
//--
//  Problem #1863
int Solution::subsetXORSum(vector<int>& nums){
    int sum = 0;

    for (int i = 0; i < nums.size(); i++){
        sum |= nums[i];
    }
    return sum << (nums.size() - 1);
}
//--
//  Problem #1356

int Solution::adriansProblem(int n){
    int x = ((n * (n + 1)) *  ((2 * n) + 1)) / 6;
    int y = (n * (n + 1)) / 2;
    return x + y;
}