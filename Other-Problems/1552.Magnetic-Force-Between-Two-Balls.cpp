// Appraoch:
// We solve this problem using binary search on the answer. 
// After sorting the positions, the minimum possible magnetic force is 1 and the maximum is the distance between the first and last position. 
// For a candidate force mid, we greedily try to place balls starting from the first position, always placing the next ball at the earliest position that is at least mid distance away from the last placed one. 
// If we can place all m balls, the force is feasible, so we try to increase it; otherwise, we decrease it. The largest feasible force found is the maximum magnetic force.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlace(vector<int> stalls, int k, int dist){
        int cows=1;
        int lastPos=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastPos>=dist){
                cows++;
                lastPos=stalls[i];
                if(cows==k)return true;
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