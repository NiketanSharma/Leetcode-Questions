// Approach:
// This solution simulates the champagne tower using dynamic programming. 
// A 2D array represents how much champagne is in each glass. We start by pouring all the champagne into the top glass. 
// Then, row by row, if any glass contains more than 1 cup, the excess amount is split equally and poured into the two glasses below it. 
// Each glass is capped at 1 cup since it cannot hold more. By propagating overflow down to the requested row, the algorithm accurately tracks how champagne flows through the tower and finally returns the amount in the target glass.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double tower[102][102] = {0.0};
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};