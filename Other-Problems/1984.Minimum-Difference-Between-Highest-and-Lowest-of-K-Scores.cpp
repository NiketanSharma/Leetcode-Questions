// Approach:
// The function minimumDifference takes a vector of integers and an integer k.
// It first sorts the vector to arrange the scores in ascending order.
// Then, it iterates through the sorted vector, considering every contiguous subarray of length k.
// For each subarray, it calculates the difference between the maximum and minimum scores (which are the last and first elements of the subarray, respectively).
// It keeps track of the minimum difference found during these iterations.
// Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the input array. The subsequent iteration takes O(n) time.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};