#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!st.empty() && st.top()<=nums[idx]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ans[idx]=st.top();
                }
            }
            st.push(nums[idx]);
        }
        return ans;
    }
};
// Approach:
// This solution for the Next Greater Element II problem uses a stack to efficiently find the next greater element for each number in a circular array.
// It iterates through the array twice (from 2n-1 to 0), treating the array as circular by using the modulo operator to wrap around.
// For each element, it pops elements from the stack that are less than or equal to the current element, ensuring that the top of the stack always contains the next greater element.
// If the current index is within the bounds of the original array (i < n), it checks if the stack is not empty and assigns the top of the stack as the next greater element for the current index. 
// If the stack is empty, it leaves the default value of -1 in the answer vector. Finally, it pushes the current element onto the stack for future comparisons.