// Calculate the total number of apples using accumulate.
// Sort the capacity array in descending order.
// Start placing apples in boxes with the largest capacity first.
// Subtract each box’s capacity from the total apples.
// Count the number of boxes used.
// Stop and return the count as soon as all apples are accommodated.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cnt = 0;
        for(int i = 0 ; i < capacity.size() ; i++){
            total -= capacity[i];
            cnt++;
            if(total <= 0){
                return cnt;
            }
        }
        return cnt;
    }
};