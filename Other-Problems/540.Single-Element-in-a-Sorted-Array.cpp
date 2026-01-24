// Approach:
// The function singleNonDuplicate takes a sorted vector of integers where every element appears twice except for one element.
// It uses a binary search approach to find the single non-duplicate element.
// The search space is halved in each iteration by checking the mid index and its neighbors.
// If the mid index is even and the element at mid is equal to the next element,
// or if the mid index is odd and the element at mid is equal to the previous element,
// it means the single element is in the right half; otherwise, it's in the left half.
// Time Complexity: O(log n), where n is the number of elements in the input array, since the search space is halved in each iteration.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};