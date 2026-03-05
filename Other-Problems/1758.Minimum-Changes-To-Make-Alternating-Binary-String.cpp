// Approach:
// The idea is to convert the given string into an alternating binary string with the minimum number of changes. 
// There are only two possible valid alternating patterns: starting with '0' (010101...) or starting with '1' (101010...). 
// The helper function counts how many characters need to be changed to make the string follow a specific pattern. 
// It checks each index: if the index is even, the character should match the starting character (ch), and if the index is odd, it should be the opposite. 
// We calculate the number of changes needed for both patterns and return the minimum of the two, which represents the least operations required.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int help(string& s, char ch) {
        int ans = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(!(i & 1) && s[i] != ch) ans++;
            else if((i & 1) && s[i] == ch) ans++;
        }
        
        return ans;
    }
    
    int minOperations(string s) {
        int opt1 = help(s, '0');
        int opt2 = help(s, '1');
        
        return min(opt1, opt2);
    }
};