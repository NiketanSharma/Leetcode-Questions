// Approach:
// This approach first counts the number of trailing zeros in each row of the grid and stores them in an array. 
// For each row i, we need at least n - i - 1 trailing zeros so that all elements above the main diagonal remain zero. 
// We then search for the nearest row below that satisfies this condition. 
// If no such row exists, we return -1. If found, we bring that row up to position i using adjacent swaps and count the swaps. 
// This greedy strategy ensures the minimum number of swaps with a time complexity of O(n²) and space complexity of O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            zeros[i] = count;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && zeros[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};