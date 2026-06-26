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
class Compare{
public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>,Compare>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next!=nullptr){
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};
// Approach:
// This solution merges k sorted linked lists using a min-heap (priority queue).
// First, it pushes the head of each non-empty list into the priority queue. The priority queue is ordered by the node values, ensuring that the smallest node is always at the top.
// Then, it repeatedly extracts the smallest node from the priority queue, appends it to the merged list, and pushes the next node from the extracted node's list into the priority queue (if it exists).
// This process continues until the priority queue is empty, resulting in a fully merged sorted linked list. The overall time complexity is O(N log k), where N is the total number of nodes across all lists and k is the number of lists, due to the heap operations. The space complexity is O(k) for storing the nodes in the priority queue.