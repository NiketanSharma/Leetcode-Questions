// Approach:
// The approach first sorts the array so that elements are in increasing order. 
// Then it uses a sliding window (two pointers) technique to find the largest contiguous subarray where the maximum element is at most k times the minimum element. 
// Pointer i marks the start of the window and j expands the end. If nums[j] > nums[i] * k, the window becomes invalid, so i is moved forward until the condition is satisfied again. 
// During this process, the algorithm keeps track of the maximum valid window length (maxLen). Since we want the minimum removals, the answer is the total number of elements minus this longest valid subarray, i.e., n - maxLen.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int maxLen=0;
        for(int j=0;j<n;j++){
            while((long long)nums[j]>(long long)nums[i]*k){
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return n-maxLen;
    }
};