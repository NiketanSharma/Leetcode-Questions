// Approach:
// You use a balance counter to track the nesting depth of parentheses while scanning the string once. 
// When you see '(', you add it to the result only if the current balance is already greater than 0 (so you skip the outermost opening bracket), then increase the balance. 
// For ')', you first decrease the balance and add it to the result only if the balance remains greater than 0 (skipping the outermost closing bracket). 
// This effectively removes the outer parentheses of each primitive valid substring.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int n=s.length();
        int balance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(balance>0){
                    res+=s[i];
                }
                balance++;
            }else{
                balance--;
                if(balance>0)res+=s[i];
            }
        }
        return res;
    }
};