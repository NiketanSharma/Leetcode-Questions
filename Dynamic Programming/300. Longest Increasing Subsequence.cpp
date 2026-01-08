//Approach:
// Use Dynamic Programming where LIS[i] represents the length of the longest increasing subsequence ending at index i.
// Initialize all LIS[i] to 1 since the minimum length for each element is 1 (the element itself).
// Iterate through each element and for each element, check all subsequent elements.   
// If a subsequent element is greater than the current element, update LIS for that subsequent element.
// Keep track of the maximum value in the LIS array which will be the length of the longest increasing subsequence.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    LIS[j]=max(LIS[j],LIS[i]+1);
                    ans=(max(LIS[j],ans));
                }
            }
        }
        return ans;
    }
};