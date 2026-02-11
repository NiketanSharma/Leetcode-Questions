// Approach:
// We have created an unordered map to store the frequency of each element occurring and then is an element is foud again we return true
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};