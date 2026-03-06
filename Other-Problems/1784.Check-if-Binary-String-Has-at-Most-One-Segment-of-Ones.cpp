// Approach:
// The idea is to ensure that the binary string contains only one continuous block of 1s. 
// We iterate through the string, and whenever we encounter a 0, we move forward through all consecutive 0s using a while loop. 
// If after these 0s we find another 1, it means the 1s appear in more than one segment (pattern 1 → 0 → 1). 
// In that case we return false. If we finish scanning the string without finding such a pattern, it means all 1s are in a single contiguous segment, so we return true.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=0;i<s.length();i++){
            while(s[i]=='0'){
                i++;
                if(s[i]=='1')return false;
            }
        }
        return true;
    }
};