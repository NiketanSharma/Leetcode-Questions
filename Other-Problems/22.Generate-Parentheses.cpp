#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string>ans;
    void backtrack(string curr,int open,int close,int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n)backtrack(curr+'(',open+1,close,n);
        if(close<open)backtrack(curr+')',open,close+1,n);
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;
    }
};
// Approach:
// This solution generates all combinations of well-formed parentheses using a backtracking approach.
// The `backtrack` function builds the current string of parentheses (`curr`) while keeping track of the number of open and close parentheses used.
// It ensures that at any point, the number of close parentheses does not exceed the number of open parentheses, and it only adds an open parenthesis if the count of open parentheses is less than `n`.