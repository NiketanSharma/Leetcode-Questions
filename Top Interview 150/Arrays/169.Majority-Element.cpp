// Approach:
// The function majorityElement takes a vector of integers nums as input and returns the majority element, which is the element that appears more than n/2 times in the array.
// It first sorts the array in non-decreasing order.
// Since the majority element appears more than half the time, it must occupy the middle position of the sorted array.
// Therefore, the function returns the element at index n/2 after sorting.
// Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()/2;
        return nums[n];
    }
};