// Approach:
// This solution checks if two strings are isomorphic by maintaining two hash maps to ensure a one-to-one mapping between characters. 
// As we iterate through both strings simultaneously, mp1 stores the mapping from characters of s to t, and mp2 stores the reverse mapping from t to s. For each character pair (c1, c2), we verify that if a mapping already exists, it is consistent; otherwise, we return false. 
// If no conflicts occur throughout the traversal, it means every character maps uniquely and consistently, so we return true. 
// The approach runs in O(n) time with constant extra space.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (mp1.count(c1) && mp1[c1] != c2) return false;
            if (mp2.count(c2) && mp2[c2] != c1) return false;
            mp1[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};