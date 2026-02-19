// Approach:
// This solution works by tracking lengths of consecutive groups of the same character instead of checking all substrings. 
// We maintain strk as the length of the current group and prev as the length of the previous group. 
// When the character changes, we shift strk into prev and reset strk to 1. 
// At each step, if the current group length (strk) is less than or equal to the previous group length (prev), we increment the result because we can form a valid binary substring. 
// Essentially, the total count equals the sum of min(previous_group_length, current_group_length) for every adjacent group pair, achieved efficiently in one pass with O(n) time and O(1) space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, strk = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) strk++;
            else {
                prev = strk;
                strk = 1;
            }
            if (strk <= prev) res++;
        }
        return res;
    }
};