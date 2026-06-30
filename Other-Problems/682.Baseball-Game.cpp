#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string s : operations){
            if(s=="+"){
                int x=st.top();
                st.pop();
                int y=x+st.top();
                st.push(x);
                st.push(y);
            }else if(s=="D"){
                st.push(st.top()*2);
            }else if(s=="C"){
                st.pop();
            }else{
                st.push(stoi(s));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
// Approach:
// This solution for the Baseball Game problem uses a stack to keep track of valid scores. 
// It iterates through the operations, performing actions based on the type of operation: adding a new score, doubling the last score, summing the last two scores, or removing the last score. 
// Finally, it sums all valid scores in the stack to return the total score.