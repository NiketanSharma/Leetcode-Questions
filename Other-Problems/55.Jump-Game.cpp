// Approach:
// This solution uses a greedy strategy from right to left. 
// It starts by setting the destination (des) as the last index and moves backward through the array. 
// For each index i, it checks if from i we can reach the current destination (i + nums[i] >= des). 
// If yes, it updates the destination to i, meaning this position can eventually reach the end. 
// After scanning all elements, if the destination becomes index 0, then the first index can reach the last index, so the jump is possible.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canJump(vector<int> &nums){
        // int a = 0;
        // for (int i = 0;i < nums.size();i++) {
        //     if (i > a) return false;
        //     a = max(a, i + nums[i]);
        // }
        // return true;

        int des=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(des<=nums[i]+i){
                des=1;
            }
        }
        return des==0;
    }
};