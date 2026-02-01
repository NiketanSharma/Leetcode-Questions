//Approach:
// The first element will always be in olution so add it first in sum
// Now just add the next 2 minimum element in the array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=0;
        sum+=nums[0];
        sort(nums.begin()+1,nums.end());
        sum+=nums[1];
        sum+=nums[2];
        return sum;
    }
};