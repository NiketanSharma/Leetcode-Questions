// Approach:
// This solution uses dynamic programming to count the number of distinct ways to climb n stairs when you can take 1 or 2 steps at a time. 
// The key idea is that the number of ways to reach step i is the sum of ways to reach steps i-1 and i-2, since the last move could be from either of those steps. 
// Base cases handle n ≤ 2. A DP array stores intermediate results to avoid recomputation, and the final answer is dp[n].
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};