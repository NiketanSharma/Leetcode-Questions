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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(temp==nullptr)return head;
            temp=temp->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        int count=0;
        ListNode* nextNode=nullptr;
        while(curr!=nullptr && count<k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            count++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};
// Approach:
// The solution reverses nodes in groups of k using recursion.
// First, it checks if there are at least k nodes left in the list. If not, it returns the head as is.
// If there are k nodes, it reverses the first k nodes and then recursively calls the function for the next group of k nodes.
