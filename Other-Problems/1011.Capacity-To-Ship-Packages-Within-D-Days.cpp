// Approach:
// This solution uses binary search on the answer to find the minimum ship capacity. 
// The lowest possible capacity is the maximum single package weight, and the highest is the sum of all weights. 
// For a chosen mid capacity, we simulate shipping (totalDays) by loading packages in order until the capacity overflows, then moving to the next day. 
// If the required days are within the given limit, we try a smaller capacity; otherwise, we increase it. 
// Repeating this narrows down to the minimum feasible capacity that ships all packages within the given days.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        while(l<=h)
        {
            int mid=(l+h)/2;
            int daysToParcel=totalDays(weights,mid);
            if(daysToParcel<=days)h=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int totalDays(vector<int> nums,int capacity){
        int days=1;
        int temp=capacity;
        for(int i=0;i<nums.size();i++){
            if(temp-nums[i]<0){
                days++;
                temp=capacity;
            }
            temp-=nums[i];
        }
        return days;
    }
};