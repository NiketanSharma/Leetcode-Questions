// Approach:
// The function numberOfSubstrings takes a string s consisting of characters 'a', 'b', and 'c' as input and returns the number of substrings that contain at least one occurrence of each character.
// It uses a sliding window approach with two pointers (left and right) to maintain a window that contains all three characters.
// As it expands the right pointer, it updates the count of each character in the current window.
// When the window contains all three characters, it calculates the number of valid substrings that can be formed with the current right pointer and adds it to the result.
// It then shrinks the window from the left until it no longer contains all three characters, updating the counts accordingly.
// Time Complexity: O(n), where n is the length of the input string.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}; 
        int left = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.length() - i;
                count[s[left] - 'a']--;
                left++;
            }
        }
        return result;
    }
};
