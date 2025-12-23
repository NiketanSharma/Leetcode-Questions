// Approach Used:
// Use an unordered_set to store elements that have already been seen.
// Initialize an index idx to track the position for unique elements in the array.
// Traverse the array element by element.
// If the current element is not in the set, insert it into the set.
// Place the element at arr[idx] and increment idx.
// After traversal, the number of unique elements is given by the size of the set (or idx).

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    unordered_set<int> s; 
    int idx = 0;  
    for(int i=0;i<arr.size();i++)
    {
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            arr[idx++]=arr[i];
        }
    }
    return s.size();        
    }
};

