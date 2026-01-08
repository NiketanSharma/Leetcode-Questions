//Approach:
// Use a set to track previously seen numbers to detect cycles.
// For each number, calculate the sum of the squares of its digits.
// If the sum equals 1, return true (happy number).
// If a number repeats (found in the set), return false (not a happy number).
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;  
        while (n != 1) {
            if (seen.count(n)) return false;  
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return true; 
    }
};