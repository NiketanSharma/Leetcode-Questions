// Approach:
// The idea is to use backtracking (DFS) to try forming 4 equal sides of a square. 
// First, we check if the total length of all matchsticks is divisible by 4—otherwise, forming a square is impossible. 
// We then sort the matchsticks and try placing them one by one (starting from the largest for pruning) into one of four “buckets,” each representing a side of the square. 
// While placing, we ensure no bucket exceeds the target side length and skip duplicate states to avoid redundant work. If all matchsticks are placed successfully, we return true; otherwise, we backtrack and try other combinations.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<int>& matchsticks, vector<int>& kow, int index, int target){
        if(index == -1){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if(((kow[i] + matchsticks[index]) > target) or (i > 0 and kow[i] == kow[i - 1])){
                continue;
            }
            kow[i] += matchsticks[index];
            if(dfs(matchsticks, kow, index - 1, target)){
                return true;
            } 
            kow[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i : matchsticks){
            sum += i;
        }
        if(sum%4 != 0 or matchsticks.size() < 3){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> kow(4, 0);
        return dfs(matchsticks, kow, matchsticks.size() - 1, sum/4);
    }
};