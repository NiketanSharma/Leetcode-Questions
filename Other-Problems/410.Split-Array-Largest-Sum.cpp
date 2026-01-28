// Approach:
// This solution applies binary search on the minimum possible largest subarray sum. 
// The search range is from the maximum element (since no subarray can be smaller than that) to the sum of all elements. 
// For a guessed maximum sum (mid), the ways function greedily splits the array into subarrays such that no subarray exceeds mid. 
// If the number of required subarrays is within the allowed limit, we try to minimize the maximum sum by moving left; otherwise, we increase it. 
// The final answer is the smallest feasible maximum subarray sum.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        while(l<=h)
        {
            int mid=(l+h)/2;
            int daysToParcel=ways(weights,mid);
            if(daysToParcel<=days)h=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int ways(vector<int> nums,int capacity){
        int way=1;
        int temp=capacity;
        for(int i=0;i<nums.size();i++){
            if(temp-nums[i]<0){
                way++;
                temp=capacity;
            }
            temp-=nums[i];
        }
        return way;
    }
};