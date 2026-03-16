// Approach:
// The idea is to treat every cell in the grid as the top vertex of a rhombus. 
// First consider size 0 rhombus, which is just the single cell value. 
// Then gradually expand the rhombus by increasing its size k, ensuring it stays inside the grid. 
// For each valid size, compute the border sum of the rhombus by traversing its four diagonal edges (top→right, right→bottom, bottom→left, left→top). 
// Store every rhombus sum in a set to keep values unique and sorted, and maintain only the largest three sums by removing the smallest when the set size exceeds three. 
// Finally, return these three largest distinct sums in decreasing order.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                if (st.size() > 3) st.erase(st.begin());
                for (int k = 1; i + 2*k < m && j-k >= 0 && j+k < n; k++) {
                    int sum = 0;
                    int r = i, c = j;
                    for (int t = 0; t < k; t++) sum += grid[r++][c++];
                    for (int t = 0; t < k; t++) sum += grid[r++][c--];
                    for (int t = 0; t < k; t++) sum += grid[r--][c--];
                    for (int t = 0; t < k; t++) sum += grid[r--][c++];
                    st.insert(sum);
                    if (st.size() > 3) st.erase(st.begin());
                }
            }
        }
        return vector<int>(st.rbegin(), st.rend());
    }
};