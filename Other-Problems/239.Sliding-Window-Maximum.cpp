// Approach:
// This approach uses a deque (double-ended queue) to efficiently track indices of useful elements for each window. 
// The deque stores indices in decreasing order of their values, so the front always contains the index of the maximum element of the current window.
// For each index:
// Remove elements from the front if they are out of the current window (i - k).
// Remove elements from the back while their value is smaller than the current element (since they can never be maximum).
// Push the current index into the deque.
// Once the first window is formed (i >= k-1), the front of the deque gives the maximum for that window.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};