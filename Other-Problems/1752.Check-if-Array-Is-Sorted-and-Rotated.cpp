// Approach :
// You scan the array once and count how many times the sorted order breaks (i.e., when a current element is smaller than the previous one). 
// In a sorted and rotated array, this break can happen at most once. 
// After the loop, you also compare the last element with the first to ensure the circular sorted order holds. 
// If the total number of breaks is more than 1, the array is not sorted and rotated; otherwise, it is valid.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int check=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])check++;
        }
        if(nums[n-1]>nums[0])check++;
        if(check>1)return false;
        return true;
    }
};