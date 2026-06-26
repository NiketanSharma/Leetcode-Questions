#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        int partsize=count/k;
        int extra=count%k;
        vector<ListNode*>ans;
        ListNode* curr=head;
        for(int i=0;i<k;i++){
            if(curr==nullptr){
                ans.push_back(nullptr);
                continue;
            }
            ans.push_back(curr);
            int size=partsize+(extra>0?1:0);
            if(extra>0)extra--;
            for(int j=1;j<size;j++){
                curr=curr->next;
            }
            ListNode* nextpart=curr->next;
            curr->next=nullptr;
            curr=nextpart;
        }
        return ans;
    }
};
// Approach:
// This solution splits a linked list into k parts as evenly as possible.
// First, it counts the total number of nodes in the linked list. Then, it calculates the base size of each part (count/k) and the number of extra nodes (count%k) that need to be distributed among the first few parts.
// It iterates through the linked list, creating each part by moving the current pointer and breaking the link after the required number of nodes for that part. 
// If there are extra nodes, they are added to the first few parts. The process continues until all k parts are created, and any remaining parts are filled with nullptr if there are not enough nodes.   
