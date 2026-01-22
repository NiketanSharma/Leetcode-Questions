// Approach:
// The function subarraySum takes a vector of integers and an integer k as input and returns the number of continuous subarrays
// whose sum equals k.
// It uses a hash map to store the cumulative sums and their frequencies.
// As it iterates through the array, it calculates the cumulative sum and checks if there exists a previous cumulative sum
// such that the difference between the current cumulative sum and that previous sum equals k.
// If such a previous sum exists, it means there is a subarray that sums to k, and the count of such subarrays is updated accordingly.
// Time Complexity: O(n), where n is the number of elements in the input array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};