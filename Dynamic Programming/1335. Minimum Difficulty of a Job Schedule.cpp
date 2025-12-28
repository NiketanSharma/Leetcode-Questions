//Approach:
// If the number of jobs n is less than the number of days D, return -1 (impossible case).
// Use Dynamic Programming where dp[i] represents the minimum total difficulty to schedule jobs starting from index i.
// Initialize dp[n] = 0 as the base case (no jobs left).
// Iterate day by day (1 to D) and recompute dp for valid indices.
// For each starting index i, try all possible job partitions for the current day.
// Track the maximum job difficulty (maxd) for the current day.
// Update dp[i] with the minimum value of maxd + dp[j+1].
// Final answer is stored in dp[0].

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDifficulty(vector<int>& A, int D) {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};