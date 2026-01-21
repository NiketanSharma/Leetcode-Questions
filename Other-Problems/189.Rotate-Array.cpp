//Approach:
// First, reverse the entire array.
// Then, reverse the first k elements to restore their original order.
// Finally, reverse the remaining n-k elements to restore their original order.
// This effectively rotates the array to the right by k steps.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};