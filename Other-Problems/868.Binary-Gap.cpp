// Approach:
// You first compute the binary length of n using log2(n), then convert n into a 64-bit binary string using bitset<64>. 
// You trim the leading zeros so that only the meaningful binary part remains. 
// Then, you iterate through the string: whenever you encounter a '1', you start counting the distance to the next '1' by moving forward in the string. 
// If another '1' is found, you update the maximum distance (ans). 
// If no further '1' is found, you ignore that count. Finally, you return the maximum distance between two consecutive set bits (binary gap).
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int len=(int)(log2(n));
        string s=bitset<64>(n).to_string().substr(64 - len -1);
        for(int i=0;i<s.length();i++){
            int count=0;
            if(s[i]=='1'){
                for(int j=i+1;j<s.length();j++){
                    count++;
                    if(s[j]=='1')break;
                    if(j==s.length()-1 && s[j]=='0')count=0;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};