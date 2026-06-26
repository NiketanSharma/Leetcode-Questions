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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        while(head!=nullptr){
            ListNode* nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf=reverseList(slow);
        ListNode* firstHalf=head;
        while(secondHalf!=nullptr){
            if(firstHalf->val!=secondHalf->val)return false;
            secondHalf=secondHalf->next;
            firstHalf=firstHalf->next;
        }
        return true;
    }
};
// Approach:
// Use two pointers, slow and fast, to find the middle of the linked list. 
// Move slow by one step and fast by two steps. When fast reaches the end, slow will be at the middle.
// Reverse the second half of the linked list starting from the slow pointer.