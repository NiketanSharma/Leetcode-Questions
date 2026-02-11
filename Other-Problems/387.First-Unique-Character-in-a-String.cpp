// Approach:
// This solution uses a hashmap to count character frequencies and then finds the first unique character. 
// First, it iterates through the string and stores how many times each character appears using an unordered_map. 
// Next, it scans the string again in order and checks the frequency of each character in the map. 
// The first character with frequency 1 is the first non-repeating character, so its index is returned. 
// If no such character exists, the function returns -1. This approach runs in O(n) time with O(1) extra space (since the character set is limited).
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(char x : s){
            mp[x]++;
        }
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1)return i;
        }
        return -1;
    }
};