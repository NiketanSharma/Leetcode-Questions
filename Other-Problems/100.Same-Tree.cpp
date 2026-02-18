// Approach:
// This solution for LeetCode Same Tree uses a recursive depth-first comparison of both trees. 
// At each step, it checks three conditions: if both nodes are nullptr, the trees match at that branch; 
// if only one is nullptr or their values differ, the trees are not the same. 
// Otherwise, it recursively compares the left children and right children of both nodes. 
// The trees are considered identical only if both subtrees match structurally and in value, ensuring a complete node-by-node comparison.
#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
        if(p == nullptr && q == nullptr)return true;
        if(p == nullptr || q == nullptr)return false;
        if(p->val != q->val)return false;
        return isSameTree(p->left,q->left)  && isSameTree(p->right,q->right);
    }
};