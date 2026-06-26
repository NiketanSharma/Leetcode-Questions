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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode*temp=curr->next;
            curr->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return dummy->next;
    }
};
// Approach:
// Use a dummy node to simplify edge cases. 
// Move a pointer `prev` to the node just before the `left` position. 
// Then, reverse the sublist from `left` to `right` by adjusting the `next` pointers of the nodes in that range. 
// Finally, return the new head of the list, which is `dummy->next`.