// Approach:
// The function removeDuplicates takes a sorted vector of integers nums as input and removes duplicates in-place such that each element appears at most twice.
// It uses a pointer k to track the position where the next unique or allowed duplicate element should
// be placed. The function iterates through the array starting from the third element (index 2).
// For each element, it checks if it is different from the element located two positions before the current position of k.
// If it is different, it means that the current element can be added to the array without exceeding the allowed duplicate count.
// The current element is then placed at the position k, and k is incremented.
// Finally, the function returns k, which represents the new length of the modified array with duplicates removed.
// Time Complexity: O(n), where n is the number of elements in the input array,
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        if (nums.size() <= 2) return nums.size();
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;       
    }
};