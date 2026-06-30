#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(char c : s){
            if(c=='#' && !st1.empty())st1.pop();
            else if(c=='#' && st1.empty())continue;
            else st1.push(c);
        }
        for(char c : t){
            if(c=='#' && !st2.empty())st2.pop();
            else if(c=='#' && st2.empty())continue;
            else st2.push(c);
        }
        return st1==st2;
    }
};
// Approach:
// This solution for the Backspace String Compare problem uses two stacks to simulate the effect of backspace characters ('#') in the input strings. 
// It iterates through each character of both strings, pushing characters onto their respective stacks unless a backspace is encountered, in which case it pops the top character from the stack if it's not empty. 
// After processing both strings, it compares the two stacks to determine if they are equal, indicating that the final processed strings are the same.