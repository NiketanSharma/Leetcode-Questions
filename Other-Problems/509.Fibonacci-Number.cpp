#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)return n;
        return fib(n-1)+fib(n-2);
    }
};

// Approach:
// This solution calculates the nth Fibonacci number using a simple recursive approach.
// The base cases are defined for n=0 and n=1, returning n directly. For other values of n, the function recursively calls itself to compute the sum of the two preceding Fibonacci numbers (fib(n-1) + fib(n-2)).