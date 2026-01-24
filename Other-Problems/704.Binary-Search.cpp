// Approach:
// The function search takes a vector of integers nums and an integer target as input and returns the index of target in nums if it exists, otherwise returns -1.
// It uses a recursive binary search algorithm to efficiently locate the target.
// The binarySearch function is a helper function that performs the actual recursive search.
// It calculates the middle index of the current search range and compares the middle element with the target
// If the middle element matches the target, it returns the index.
// If the middle element is less than the target, it recursively searches the right half of the array.
// If the middle element is greater than the target, it recursively searches the left half of the array.
// The search function initializes the search by calling binarySearch with the full range of the array.
// Time Complexity: O(log n) due to the binary search algorithm, where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1; 
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) 
            return mid;
        else if (nums[mid] < target) 
            return binarySearch(nums, mid + 1, r, target);
        else 
            return binarySearch(nums, l, mid - 1, target);
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};