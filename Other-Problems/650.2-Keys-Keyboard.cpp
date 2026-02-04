// Approach:
// The approach uses recursion based on factorization. 
// Starting from 1 A, the only way to build more characters is by copying the current string and pasting it multiple times, which effectively multiplies the count. 
// For a target n, the idea is to try all its divisors i: first recursively compute the minimum steps to get i characters, then use one Copy All and (n / i − 1) Paste operations to reach n, adding a total of n / i steps. 
// The minimum over all such possibilities is chosen. The base case is n = 1, which needs zero operations. This explores all valid construction paths and picks the optimal one.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n) {
        if (n == 1) return 0;
        int ans = n; 
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                ans = min(ans, solve(i) + (n / i));
            }
        }
        return ans;
    }
    int minSteps(int n) {
        return solve(n);
    }
};