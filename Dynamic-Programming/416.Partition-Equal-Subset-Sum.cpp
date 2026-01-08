//Approach:
// Calculate the total sum of the array. If it's odd, return false since it can't be partitioned equally.
// Set the target as half of the total sum.
// Use a 1D DP array where dp[i] indicates whether a subset with sum i can be formed.
// Initialize dp[0] to true since a sum of 0 can always be formed with an empty subset.
// For each number in the array, iterate backwards through the dp array to update possible sums.
// If dp[target] becomes true at any point, return true immediately.
// Finally, return the value of dp[target] which indicates if the target sum can be formed.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = target; i >= n; i--) {
                if (dp[i]) continue;
                if (dp[i - n]) dp[i] = true;
                if (dp[target]) return true;
            }
        }

        return false;        
    }
};