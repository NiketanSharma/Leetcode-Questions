// Approach:
// Your approach first uses an unordered_map to count frequencies of each number in the array. 
// Then, while selecting the top k elements, it repeatedly scans the map to find the element with the maximum frequency, adds that element to the result vector, and removes it from the map so it won’t be selected again. 
// This process continues until k elements are chosen. Overall, this is a brute-force frequency selection method with time complexity about O(k · n) due to repeatedly traversing the map.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x : nums){
            mp[x]++;
        }
        while(k!=0){
            int max=0;
            int element=0;
            for(auto &p : mp){
                if(p.second>max){
                    max=p.second;
                    element=p.first;
                }
            }
            ans.push_back(element);
            mp.erase(element);
        }
        return ans;
    }
};