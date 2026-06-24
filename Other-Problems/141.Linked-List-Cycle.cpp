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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
    }
};
// Approach:
// Use two pointers, slow and fast. Move slow by one step and fast by two steps.
// If there is a cycle, fast and slow will eventually meet at some point in the cycle
