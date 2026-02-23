// Approach:
// We use a sliding window of size k to extract every substring of length k from the given string s. 
// Each substring is inserted into an unordered_set to store only unique binary codes. 
// Since there are exactly 2^k possible binary strings of length k, we finally check whether the size of the set equals (1 << k). 
// If it does, it means all possible binary codes of length k are present in s; otherwise, they are not.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i = 0; i + k <= s.length(); i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};