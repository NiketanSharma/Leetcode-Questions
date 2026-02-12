// Approach:
// For every possible starting index i, you expand the substring to the right with index j and maintain a frequency array of 26 characters. 
// Each time you add a character, you treat its frequency as the target count and scan the frequency array to verify that all other characters that appear in the substring have the same count. 
// If they do, the substring is balanced, so you update the maximum length. This checks all substrings in O(n² · 26) time, which is effectively O(n²) since the alphabet size is constant.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longestBalanced(string s){
        int n=s.length();
        int maxL=0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int tar=freq[s[j]-'a'];
                bool flag=true;
                for(int k=0;k<26;k++){
                    if(freq[k]>0 && freq[k]!=tar){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    maxL=max(maxL,j-i+1);
                }
            }
        }
        return maxL;
    }
};