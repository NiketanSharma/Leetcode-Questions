// Approach:
// You first reverse the entire string so the word order becomes reversed. 
// Then you traverse the string and extract each word by collecting characters until a space appears. 
// For every completed word, you reverse it again to restore its correct spelling and append it to the result with proper spacing. 
// Finally, you also process the last word after the loop. This results in all words appearing in reversed order while maintaining correct character order within each word.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res = "", word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                reverse(word.begin(), word.end());
                if (!res.empty()) res += " ";
                res += word;
                word = "";
            }
        }
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            if (!res.empty()) res += " ";
            res += word;
        }
        return res;
    }
};