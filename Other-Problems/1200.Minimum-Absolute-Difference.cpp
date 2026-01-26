// Approach:
// The function minimumAbsDifference takes a vector of integers as input.
// It first sorts the array to arrange the elements in ascending order.
// Then, it calculates the minimum absolute difference between any two consecutive elements in the sorted array.
// After determining the minimum difference, it iterates through the array again to find all pairs of elements that have this minimum difference.
// These pairs are stored in a vector of vectors and returned as the result.
// Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the input array. The subsequent iterations take O(n) time.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0];
        for(int i = 0; i < n - 1; i ++){
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }   
        vector<vector<int> > sol;
        for(int i = 0; i < n - 1; i ++){
            if(arr[i + 1] - arr[i] == min_diff){
                sol.push_back({arr[i], arr[i + 1]});
            }
        }
        return sol;
    }
};
