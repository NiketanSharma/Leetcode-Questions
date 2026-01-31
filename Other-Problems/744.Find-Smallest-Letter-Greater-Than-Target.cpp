// Approach:
// Since the letters array is sorted, we apply binary search to find the smallest character greater than the target. 
// We compare the middle element with the target: if it is greater, we store it as a possible answer and move left to find a smaller valid character; otherwise, we move right. 
// If no character greater than the target is found during the search, we return the first element to handle the wrap-around case. 
// This reduces the time complexity to O(log n).
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        char ans = letters[0];   
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};