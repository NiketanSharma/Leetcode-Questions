// Approach:
// Use Binary search to find the peak element by dividing into 2 parts and checking if its on right or left and if found return the value.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=(l+r)/2;
            if(nums[m]<nums[m+1])l=m+1;
            else r=m;
        }
        return l;
    }
};