// Approach:
// The function containsNearbyDuplicate takes a vector of integers and an integer k as input and returns true if there are
// two distinct indices i and j in the array such that nums[i] == nums[j] and the absolute difference between i and j is at most k.
// It uses an unordered set to keep track of the elements within the current sliding window of size k.
// As it iterates through the array, it adds the current element to the set and checks if the element already exists in the set.
// If it does, it returns true. If the size of the set exceeds k, it removes the element that is out of the current window.
// Time Complexity: O(n), where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }
            if (set.count(nums[i])) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};