// Approach:
// We iterate through the whole nums array and at each step take the difference of target and nums[i] and find if it is present or not.
// if it is present the we return the two indexes else we update the map with nums[i]
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int a=target-nums[i];
            for(int i=0;i<n;i++){
                if(mp.find(a)!=mp.end()){
                    return {mp[a],i};
                }
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};