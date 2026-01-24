// Approach:
// The function rotate takes a vector of integers nums and an integer k as input and rotates the array to the right by k steps.
// It first calculates the effective number of rotations needed by taking k modulo the size of the array.
// The function then reverses the entire array. 
// Next, it reverses the first k elements to place them in their correct positions.
// Finally, it reverses the remaining n-k elements to restore their original order.
// Time Complexity: O(n), where n is the number of elements in the input array, since each reversal operation takes linear time.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};