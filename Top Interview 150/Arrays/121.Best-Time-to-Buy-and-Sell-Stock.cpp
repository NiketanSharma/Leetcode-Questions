// Approach:
// The approach scans the price array once while keeping track of the minimum price seen so far and the maximum profit. 
// For each day, it assumes buying at the lowest price up to that point and selling on the current day, updating the maximum profit if this difference is larger. 
// This greedy method ensures the best buy-sell combination in O(n) time and O(1) space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int price : prices){
            minPrice=min(minPrice,price);
            maxProfit=max(maxProfit,price-minPrice);
        }
        return maxProfit;
    }
};