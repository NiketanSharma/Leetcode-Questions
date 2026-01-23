// Approach:
// The function longestOnes takes a vector of integers nums (consisting of 0s and 1s) and an integer k as input and returns the length of the longest contiguous subarray that contains at most k zeros.
// It uses a sliding window approach with two pointers (left and right) to maintain a window
// that contains at most k zeros.
// As it expands the right pointer, it counts the number of zeros in the current window.
// When the count of zeros exceeds k, it shrinks the window from the left until the count of zeros is at most k, updating the left pointer accordingly.
// It keeps track of the maximum length of the valid window encountered during the process.
// Time Complexity: O(n), where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int maxLength=0;
        int zeroCount=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[left]==0){
                    zeroCount--;
                }
                left++;
            }
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};