// Approach:
// This solution uses a greedy approach where we add profit whenever the stock price increases from one day to the next. 
// Instead of trying to find exact buy-sell pairs, we simply capture every upward movement by adding the difference prices[i] - prices[i-1] when it’s positive. 
// This effectively simulates buying on the previous day and selling on the current day for every profitable rise. By summing all these gains, we get the maximum possible profit with unlimited transactions in O(n) time and O(1) space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};