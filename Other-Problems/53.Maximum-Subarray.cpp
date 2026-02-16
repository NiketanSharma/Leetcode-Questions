// Approach:
// This solution uses Kadane’s Algorithm to find the maximum subarray sum in linear time. 
// It iterates through the array while maintaining a running sum of the current subarray. 
// At each step, the sum is updated by adding the current element and compared with the maximum answer found so far. 
// If the running sum becomes negative, it is reset to 0 because a negative sum would only reduce the total of any future subarray. 
// The variable ans keeps track of the highest sum encountered, ensuring the maximum subarray sum is returned.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int ans = nums[0];
        int sum = 0; 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans=max(ans,sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};