// Approach:
// The function minPairSum takes a vector of integers nums as input and returns the minimum possible value of the maximum pair sum after pairing the elements optimally.
// It first sorts the array to arrange the elements in ascending order.
// Then, it uses two pointers: one starting from the beginning (i) and the other from the end (r) of the sorted array.
// In each iteration, it calculates the sum of the elements at these two pointers and updates the maximum pair sum encountered so far.
// The pointers are then moved closer to each other (i is incremented and r is decremented) to consider the next pair.
// This process continues until all elements are paired.
// Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int r = nums.size() - 1;
        int maxSum = 0;
        while (i < r) {
            maxSum = max(maxSum, nums[i] + nums[r]);
            i++;
            r--;
        }
        return maxSum;
    }
};