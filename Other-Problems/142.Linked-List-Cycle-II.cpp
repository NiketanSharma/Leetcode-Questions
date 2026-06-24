#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ListNode* temp=head;
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                }
                return temp;
            }
        }
        return nullptr;
    }
};
// Approach:
// Use two pointers, slow and fast. Move slow by one step and fast by two steps.
// If there is a cycle, fast and slow will eventually meet at some point in the cycle
// Once they meet, initialize a new pointer from the head of the list and move both this pointer and the slow pointer one step at a time.
// The point at which they meet again will be the start of the cycle.