// Approach:
// We build Pascal’s Triangle iteratively using a 2D vector. 
// For each row i, we create a vector of size i+1 initialized with 1s, since the first and last elements of every row are always 1. 
// For the inner elements, we use the property of Pascal’s Triangle: each value is the sum of the two elements directly above it from the previous row. 
// We repeat this process for all rows and store them in the result vector. 
// The time complexity is O(n²) and the space complexity is also O(n²) since we store the entire triangle.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};