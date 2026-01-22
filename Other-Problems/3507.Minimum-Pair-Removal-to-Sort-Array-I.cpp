// Approach:
// The function minimumPairRemoval takes a vector of integers as input and returns the minimum number of
// pair removal operations needed to sort the array in non-decreasing order.
// It repeatedly finds the adjacent pair of elements with the smallest sum, merges them into a single   
// element, and counts the number of such operations until the array is sorted.
// The helper function isSorted checks if the array is sorted.
// Time Complexity: O(n^2) in the worst case, where n is the number of elements in the array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr = nums;
        int ops = 0;
        while (!isSorted(arr)) {
            int minSum = INT_MAX;
            int idx = 0;
            for (int i = 0; i < arr.size() - 1; i++) {
                int s = arr[i] + arr[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }
            arr[idx] = minSum;
            arr.erase(arr.begin() + idx + 1);
            ops++;
        }
        return ops;
    }
    bool isSorted(const vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }
};