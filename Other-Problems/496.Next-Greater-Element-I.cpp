#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
// Approach:
// This solution for the Next Greater Element I problem uses a stack to efficiently find the next greater element for each number in nums1 based on their order in nums2.
// It iterates through nums2 in reverse order, maintaining a stack of potential next greater elements. 
// For each element in nums2, it pops elements from the stack that are less than or equal to the current element, ensuring that the top of the stack always contains the next greater element. 
// If the stack is empty, it means there is no greater element, and -1 is recorded. The results are stored in a map for quick lookup when processing nums1. Finally, it constructs the answer vector by looking up each element of nums1 in the map.