// Approach:
// This approach uses a min-heap (priority queue) of size k to find the k-th largest element. 
// We iterate through the array and push each element into the min-heap. 
// If the heap size becomes greater than k, we remove the smallest element (top of min-heap). 
// This way, the heap always stores the k largest elements seen so far. 
// After processing all elements, the top of the heap represents the k-th largest element, because it is the smallest among those k largest elements.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};