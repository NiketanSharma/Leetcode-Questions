// Approach:
// Your approach builds a new transformed array by using circular indexing. 
// For each index i, you shift the position by nums[i] steps and pick the element from that new position. 
// Since the shift can be positive or negative and may go out of bounds, you use modular arithmetic ((i + nums[i]) % n + n) % n to wrap the index safely within the range [0, n-1]. 
// This ensures correct handling of negative values and circular movement. You repeat this for all elements and store the results in a new array ans, achieving an overall time complexity of O(n).
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[((i + nums[i]) % n + n) % n];
        }
        return ans;
    }
};