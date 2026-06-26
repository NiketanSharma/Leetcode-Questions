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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1!=nullptr){
            temp->next=l1;
        }else{
            temp->next=l2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);

        return mergeList(left,right);
    }
};
// Approach:
// This solution implements merge sort on a singly linked list.
// It first finds the middle of the list using the slow and fast pointer technique, then recursively sorts the left and right halves of the list.
// Finally, it merges the two sorted halves using a helper function that merges two sorted linked lists
