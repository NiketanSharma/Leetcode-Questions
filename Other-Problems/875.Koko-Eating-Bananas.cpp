#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int> v, int h) {
        int low = 1;
        int high = *max_element(v.begin(), v.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long reqTime = 0;
            for (int bananas : v) {
                reqTime += (bananas + mid - 1) / mid;
            }
            if (reqTime <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// Approach:
// The required hours decrease as eating speed increases, so the function is monotonic.
// Search space for speed is from 1 to max(piles).
// Apply binary search on this range to find the minimum valid speed.
// For a chosen speed, compute total hours using ceil(pile / speed) for each pile.
// If total hours ≤ h, try a smaller speed; otherwise, increase the speed.
