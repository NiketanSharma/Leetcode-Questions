// Approach:
// This solution sorts the array using Bubble Sort. 
// It repeatedly compares adjacent elements and swaps them if they are in the wrong order. 
// After each pass, the largest unsorted element moves to its correct position at the end. 
// The process continues for n-1 passes or stops early if no swaps occur in a pass (meaning the array is already sorted). 
// Since the problem only contains 0, 1, and 2, this correctly sorts them in ascending order.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        bubbleSort(nums);
    }
private:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bool swapped;
    
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }        
            if (!swapped)
                break;
        }
    }
};