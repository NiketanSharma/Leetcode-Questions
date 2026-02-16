// Approach:
// You iterate through each bit of the integer from right to left and build a new number with bits placed in reverse positions. 
// Starting with the least significant bit of n, you check if it is 1 using bitwise AND. 
// If it is, you set the corresponding bit in the result at position i (starting from 31). 
// Then you right-shift n to process the next bit and decrement i. 
// This continues until all bits are processed, effectively reversing the 32-bit binary representation.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverseBits(int n) {
        unsigned int i=31,res=0;
        cout<<n;
        while(i>0){
            if(n&1)res|=(1<<i);
            i--;
            n>>=1;
        }
        return res;
    }
};