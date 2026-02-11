// Approach:
// Created an unordered map to store frequency of each distinct element in nums1
// iterated through nums2 to check whether the element is already present in map
// if it is then push it into set
// finally convert the set into a vector ans and return it
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        set<int>s;
        vector<int>ans;
        for(int x : nums1){
            mp[x]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                s.insert(nums2[i]);
            }
        }
        for(int a : s){
            ans.push_back(a);
        }
        return ans;
    }
};