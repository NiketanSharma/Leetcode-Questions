// Approach:
// The algorithm checks whether the array follows a trionic pattern: first strictly increasing, then strictly decreasing, and finally strictly increasing again. 
// It scans from the left to find the first index (peak) where the increasing order breaks, and from the right to find the first index (valley) where the final increasing order (from the end) breaks. 
// These two points split the array into three parts. It then validates that the first and last parts are non-empty and strictly increasing, and the middle part (between peak and valley) is strictly decreasing. 
// If all conditions hold, the array is trionic; otherwise, it returns false.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int peak = -1;
        int valley = n;
        for (int i = 0; i < n - 1; i++) {
            if (peak == -1 && nums[i] >= nums[i + 1])
                peak = i;
            if (valley == n && nums[n - 1 - i] <= nums[n - 2 - i])
                valley = n - 1 - i;
            if (peak > -1 && valley < n) break;
        }
        if (peak < 1 || valley > n - 2)
            return false;
        for (int i = peak; i < valley; i++)
            if (nums[i] <= nums[i + 1])
                return false;
        return true;
    }
};