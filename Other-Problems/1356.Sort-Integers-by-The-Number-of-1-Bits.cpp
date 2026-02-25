// Approach:
// This solution counts the number of set bits in each number using __builtin_popcount() and stores each number with its bit count in a vector of pairs. 
// It then sorts the vector primarily by the number of set bits in ascending order, and if two numbers have the same bit count, it sorts them by their value in ascending order. 
// Finally, it extracts the sorted numbers into a result vector and returns it.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vec;
        for(int i=0;i<arr.size();i++){
            int x=__builtin_popcount(arr[i]);
            vec.push_back({arr[i],x});
        }
        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });
        vector<int> ans;
        for(auto &q : vec){
            ans.push_back(q.first);
        }
        return ans;
    }
};