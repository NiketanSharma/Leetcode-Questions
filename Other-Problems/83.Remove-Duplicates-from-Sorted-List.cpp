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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* curr=head;
        while(curr->next!=nullptr){
            if(curr->next->val==curr->val){
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};
// Approach:
// Since the linked list is sorted, duplicates will be adjacent.
// Traverse the list with a pointer `curr`. 
// If `curr->next` has the same value as `curr`, skip the next node by setting `curr->next` to `curr->next->next`. 
// Otherwise, move `curr` to the next node. Continue until reaching the end of the list. 
// Return the modified head of the list.