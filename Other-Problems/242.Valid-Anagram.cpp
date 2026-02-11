// Approach:
// We store the frequency of each character in string s in an unordered map.
// We then traverse through string t and check if the character is in map or not.
// if character is not present we return false
// else we deecrement the frequency in map
// finally we check if the map is empty 
// if the map is empty then it is a valid anagram
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length())return false;
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        for(char c : t){
            if(mp.find(c)!=mp.end()){
                mp[c]--;
                if(mp[c]==0)mp.erase(c);
            }else{
                return false;
            }
        }
        return mp.empty();
    }
};