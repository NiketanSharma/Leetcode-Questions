#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i=s.size()-2;
        while(i>=0 && s[i]>=s[i+1]){
            i--;
        }
        if(i<0)return -1;
        int j=s.size()-1;
        while(s[j]<=s[i]){
            j--;
        }
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
        long long  ans=stoll(s);
        if(ans>INT_MAX)return -1;
        return ans;
    }
};
// Approach:
// This solution for the Next Greater Element III problem finds the next greater permutation of the digits of a given integer n. 
// It first converts the integer to a string to manipulate its digits. 
// The algorithm identifies the rightmost pair of digits where the left digit is smaller than the right digit, indicating a potential for a larger permutation. 
// It then finds the smallest digit on the right side that is larger than this identified digit, swaps them, and reverses the sequence of digits to the right of the original position to get the smallest possible number. 
// Finally, it checks if the result exceeds the 32-bit integer limit and returns -1 if it does; otherwise, it returns the next greater number.