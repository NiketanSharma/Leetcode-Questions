// Approach:
// This approach works directly on the binary string instead of converting it to an integer. 
// While the string is not "1", we simulate the given operations: 
// if the last bit is '0', the number is even, so we divide by 2 by simply removing the last character (pop_back()). 
// If the last bit is '1', the number is odd, so we simulate adding 1 in binary by flipping trailing '1's to '0' until we find a '0' to turn into '1'; 
// if all bits are '1', we prepend '1' to handle the carry. We count each operation until the string becomes "1". 
// This avoids overflow and runs in efficient time.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        int count=0;
        while (s!="1") {
            if (s.back() == '0')s.pop_back();
            else {
                int i=s.size()-1;
                while (i>=0 && s[i]=='1') {
                    s[i]='0';
                    i--;
                }
                if (i>=0)s[i]='1';
                else s="1"+s;
            }
            count++;
        }
        return count;
    }
};