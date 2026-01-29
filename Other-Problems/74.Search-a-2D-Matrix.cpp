// Approach:
// The idea is to reduce the 2D matrix search into a 1D binary search. 
// Since each row is sorted, we first iterate through the rows and check if the target can possibly lie in that row by comparing it with the first and last elements. 
// If the target falls within this range, we apply binary search on that row to find the target efficiently. 
// If no such row qualifies or binary search fails, we return false. This gives an efficient search with binary search used only where necessary.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<int>row, int target){
        int l=0;
        int h=row.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(row[mid]==target)return true;
            else if(row[mid]<target)l=mid+1;
            else h=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};