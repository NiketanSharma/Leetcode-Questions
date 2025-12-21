//Approach Used:
// Create pointers for the last valid elements of nums1 and nums2, and another pointer for the last position of nums1
// Compare the elements pointed to by the first two pointers and place the larger one at the position pointed to by the third pointer.
// Move the pointers accordingly and repeat until all elements of nums2 are merged into nums1.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1; // Pointer for the last valid element in nums1
        int p2=n-1; // Pointer for the last element in nums2
        int p=m+n-1; // Pointer for the final position in nums1
        // Merge nums1 and nums2 from the back
        while (p1>=0 && p2>=0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        // If there are remaining elements in nums2
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
