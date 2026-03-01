// Approach:
// To reduce a number to zero by subtracting deci-binary numbers (numbers containing only digits 0 and 1), the minimum number of steps required is determined by the largest digit in the number.
// Why?
// Each subtraction can reduce each digit by at most 1. Therefore, if the maximum digit in the number is d, we need at least d steps to reduce that digit to zero.
// So, the answer is simply the maximum digit present in the string.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string s) {
        int ans=0;
        for(char c : s){
            ans=max(ans,c-'0');
        }
        return ans;
    }
};