// Approach:
// In this solution, you first calculate ⌊n/3⌋ as the threshold. 
// Then you traverse the array and store the frequency of each element in an unordered_map. 
// After building the frequency map, you iterate through it and collect all elements whose count is greater than n/3 into the result vector. 
// This works because any element appearing more than n/3 times must be captured by the frequency count. 
// The overall time complexity is O(n) and the space complexity is O(n) due to the extra hash map.
#include<bits/stdc++.h>
using namespace std;
class Soultion{
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x : nums){
            mp[x]++;
        }
        for(auto &p : mp){
            if(p.second>n){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};