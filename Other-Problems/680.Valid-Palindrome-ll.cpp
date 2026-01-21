//Approach:
// Use two pointers to check characters from both ends of the string.
// When a mismatch is found, check if skipping either the left or right character results in a palindrome.
// If either check returns true, the string can be a valid palindrome after at most one deletion
// If no mismatches are found, the string is already a palindrome.
// Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string& s,int start,int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            if(s[start] != s[end]){
                return isPalindrome(s,start+1,end) || isPalindrome(s,start,end-1);
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};