// Approach:
// This approach groups anagrams by using a hash map where each key represents a sorted version of a string. 
// For every word in the input list, we sort its characters to create a canonical form (since anagrams share the same sorted order). 
// We then store the original word in the vector mapped to that sorted key. After processing all strings, we collect all the grouped values from the map into the result. 
// Sorting ensures that all anagrams map to the same key, giving an efficient overall time complexity of about O(n · k log k), where n is the number of strings and k is the average string length.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s : strs){
            string key=s;
            sort(s.begin(),s.end());
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for( auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};