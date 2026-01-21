//Approach:
// Iterate through each number in the input array.
// For even numbers, append -1 to the result array since no valid number exists.
// For odd numbers, calculate the next even number by adding 1.
// Find the lowest set bit of this even number using bitwise operations.
// Subtract half of this lowest set bit from the original odd number to get the desired result
// Append this result to the result array.
// Finally, return the constructed result array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int n : nums) {
            if (n % 2 == 0) {
                ans.push_back(-1);
            } else {
                int t = n + 1;
                int lowbit = t & -t;
                ans.push_back(n - (lowbit >> 1));
            }
        }
        return ans;
    }
};