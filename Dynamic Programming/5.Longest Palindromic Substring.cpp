//Approach:
// A 2D DP table dp[i][j] is created where dp[i][j] is true if the substring from index i to j is a palindrome.
// First, all single characters are marked as palindromes.
// Then, substrings of length 2 are checked and marked if both characters are equal.
// For substrings of length 3 or more, a substring is considered a palindrome if its first and last characters are the same and the inner substring is already a palindrome (dp[i+1][j-1]).
// While filling the table by increasing substring length, we track the starting index and maximum length of the longest palindrome found and finally return that substring.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if (n==0)return "";
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int a=0;
        int max=1;
        for(int i=0;i<n;i++) {
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++) {
            if (s[i]==s[i+1]){
                dp[i][i+1]=true;
                a=i;
                max=2;
            }
        }
        for(int len=3;len<=n;len++) {
            for (int i=0;i<=n-len;i++) {
                int j=i+len-1;
                if (s[i]==s[j]&&dp[i+1][j-1]){
                    dp[i][j]=true;
                    a=i;
                    max=len;
                }
            }
        }
        return s.substr(a,max);
    }
};
