// Approach:
// This solution adds two binary strings by simulating manual binary addition from right to left. 
// First, both strings are reversed so we can process them from the least significant bit. 
// Then we iterate up to the length of the longer string, adding corresponding digits from each string along with a carry. 
// For each step, we compute the sum, store the result bit (sum % 2) in the result string, and update the carry (sum / 2). 
// If a carry remains after the loop, it is appended. Finally, the result string is reversed to restore the correct order and returned.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < max(a.length(), b.length()); i++) {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;
            int total = digitA + digitB + carry;
            char c = (total % 2) + '0';
            res += c;
            carry = total / 2;
        }
        if (carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};