#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<sstream>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1; // Base case: one way to have zero odd numbers.
        int count = 0, prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num % 2; // Increment prefixSum for odd numbers.
            count += countMap[prefixSum - k]; // Add the number of times the (prefixSum - k) has occurred.
            countMap[prefixSum]++; // Increment the count of the current prefixSum.
        }
        
        return count;
    }
};

int main(){
    Solution s;
    vector<int>nums {1,1,2,1,1};
    int k = 3;
    cout<<s.numberOfSubarrays(nums, k)<<endl;
}