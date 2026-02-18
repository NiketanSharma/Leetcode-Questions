// Approach:
// For Jump Game on LeetCode, this solution uses a greedy strategy that tracks the farthest index reachable so far (a). 
// As we iterate through the array, if the current index i is ever greater than a, it means we cannot reach that position, so we return false. 
// Otherwise, we update a = max(a, i + nums[i]) to extend our reachable range. If we finish the loop without failing, it means we can reach the last index. 
// This runs in O(n) time with O(1) space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a = 0;
        for (int i = 0;i < nums.size();i++) {
            if (i > a) return false;
            a = max(a, i + nums[i]);
        }
        return true;

        // int des=nums.size()-1;
        // for(int i=nums.size()-1;i>=0;i--)
        // {
        //     if(des<=i+nums[i])des=i;
        // }
        // return des==0;
    }
};