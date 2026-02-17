// Approach:
// We iterate through all possible valid times on the binary watch (hours 0–11 and minutes 0–59) and count the number of set bits (1s) in their binary representations. 
// For each hour–minute pair, if the total number of 1s equals the given turnedOn, we add that formatted time to the result. 
// Since there are only 720 possible combinations, a simple brute-force check is efficient and guarantees all valid answers.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + 
                    __builtin_popcount(m) == turnedOn) {
                    
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);

                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};