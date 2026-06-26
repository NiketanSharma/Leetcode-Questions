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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        dummy->next=head;
        while(prev->next!=nullptr && prev->next->next!=nullptr){
            ListNode* first=prev->next;
            ListNode* second=first->next;
            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;
        }
        return dummy->next;
    }
};
// Approach:
// This solution swaps nodes in pairs in a singly linked list using an iterative approach.
// A dummy node is used to simplify edge cases, and a pointer `prev` is maintained to track the node before the current pair.
// In each iteration, the two nodes to be swapped (`first` and `second`) are identified, and their `next` pointers are adjusted to perform the swap.
// After swapping, `prev` is moved to the end of the swapped pair to prepare for the next iteration. 
// The process continues until there are no more pairs to swap, and the new head of the list is returned.