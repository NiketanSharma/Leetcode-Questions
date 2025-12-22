//Approach Used:
// This solution iterates through the array and copies each element not equal to val to the front using a pointer k. 
// The value of k represents the new length of the array after removing val.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};