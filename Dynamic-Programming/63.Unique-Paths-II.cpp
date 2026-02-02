// Approach:
// This solution uses dynamic programming with space optimization. 
// Instead of a 2D DP table, it maintains a 1D array dp where dp[c] represents the number of ways to reach the current cell in column c. 
// Starting with dp[0] = 1, it iterates row by row. If a cell contains an obstacle, dp[c] is set to 0 since no path can pass through it. 
// Otherwise, the number of paths to the current cell is updated by adding paths from the left (dp[c-1]) to the paths already coming from above (dp[c]). 
// This efficiently computes the total unique paths while using O(cols) extra space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]==1)return 0;
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<int>dp(cols,0);
        dp[0]=1;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(obstacleGrid[r][c]==1){
                    dp[c]=0;
                }else{
                    if(c>0){
                        dp[c]+=dp[c-1];
                    }
                }
            }
        }
        return dp[cols-1];
    }
};