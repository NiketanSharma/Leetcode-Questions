// Approach:
// This solution uses backtracking to explore all possible combinations that sum to the target. 
// Starting from a given index, at each step we have two choices: either pick the current element (and stay at the same index since elements can be reused) or skip it and move to the next index.
//  We keep reducing the target when an element is picked and store the combination when the target becomes zero. 
// The recursion stops when the target goes below zero or all elements are processed, ensuring only valid combinations are generated without duplicates.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int> arr, int idx,vector<int>combination, vector<vector<int>> &ans, int target)
    {
        if(idx == arr.size() || target<0)return;
        if(target==0){
            ans.push_back(combination);
            return;
        }
        combination.push_back(arr[idx]);
        solve(arr,idx,combination,ans,target-arr[idx]);
        combination.pop_back();
        solve(arr,idx+1,combination,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>combination;
        vector<vector<int>>ans;
        solve(arr,0,combination,ans,target);
        return ans;
    }
};