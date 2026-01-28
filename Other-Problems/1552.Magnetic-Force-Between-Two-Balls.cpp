// Appraoch:
// We solve this problem using binary search on the answer. 
// After sorting the positions, the minimum possible magnetic force is 1 and the maximum is the distance between the first and last position. 
// For a candidate force mid, we greedily try to place balls starting from the first position, always placing the next ball at the earliest position that is at least mid distance away from the last placed one. 
// If we can place all m balls, the force is feasible, so we try to increase it; otherwise, we decrease it. The largest feasible force found is the maximum magnetic force.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlace(vector<int> pos, int k, int dist){
        int ball=1;
        int lastPos=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i]-lastPos>=dist){
                ball++;
                lastPos=pos[i];
                if(ball==k)return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1;
        int high=position[n-1]-position[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlace(position,m,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};