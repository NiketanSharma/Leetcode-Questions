//Approach:
// Use a 1D DP array where dp[i] represents the length of the longest common subsequence ending with text1[i].
// Iterate through each character of text2.
// For each character in text2, maintain a variable curLength to track the maximum length of common subsequence found so far.
// For each character in text1, if the current character matches the character from text2, update dp[i] to curLength + 1.
// Update the overall longest length whenever dp[i] is updated.
// Finally, return the longest length found.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } else if (c == text1[i]) {
                    dp[i] = curLength + 1;
                    longest = max(longest, curLength + 1);
                }
            }
        }

        return longest;        
    }
};
