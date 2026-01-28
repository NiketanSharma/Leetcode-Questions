// Approach:
// Use the fact that in a sorted array, the number of missing positive integers before index i is arr[i] − (i + 1).
// This value increases as i increases, so we can apply binary search to find the first index where the count of missing numbers is greater than or equal to k
// During binary search, if missing numbers at mid are less than k, move right; otherwise, move left.
// After the search, if the final position is low, the k-th missing positive number is simply low + k.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
    }
};