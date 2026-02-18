// Approach:
// This solution for LeetCode Binary Number with Alternating Bits converts the integer into its binary string representation and then checks whether adjacent bits alternate. 
// It first finds the effective binary length using log2, extracts the relevant bits from a 64-bit binary string, and iterates through the string comparing each bit with the next one. 
// If any two consecutive bits are the same, it returns false; otherwise, if all adjacent bits differ, it returns true, confirming the number has alternating bits.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int len=(int)(log2(n));
        string s=bitset<64>(n).to_string().substr(64 - len - 1);
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1])return false;
        }
        return true;
    }
};