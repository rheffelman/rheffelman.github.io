#pragma once
#include <vector>
#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef unsigned long long llu;

class Solution
{
public:

    //  Problem #1720
    vector<int> decode(vector<int>& encoded, int first);

    //  Problem #1486
    int xorOperation(int n, int start);

    //  Problem #1342
    int numberOfSteps(int num);

    //  Problem #2220
    int minBitFlips(int start, int goal);

    //  Problem #1684
    int countConsistentStrings(string allowed, vector<string>& words);

    //  Problem #832
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image);

    //  Problem #1863
    int subsetXORSum(vector<int>& nums);

    // Problem #1356
    int adriansProblem(int n);
};