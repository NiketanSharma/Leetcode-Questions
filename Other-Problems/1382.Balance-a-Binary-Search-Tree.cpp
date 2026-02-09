// Approach:
// This approach first performs an inorder traversal of the given binary search tree to collect all node values in a sorted array, since inorder traversal of a BST naturally produces sorted output. 
// Then it rebuilds a balanced BST from this sorted array using a divide-and-conquer strategy: it repeatedly selects the middle element as the root and recursively constructs the left and right subtrees from the left and right halves of the array. 
// Choosing the middle element each time ensures the height of the new tree is minimized, resulting in a balanced BST with time complexity O(n) and space complexity O(n).
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
    void inorder(TreeNode* node, vector<int>& vals) {
        if(!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }
    TreeNode* build(const vector<int>& vals, int l, int r) {
        if(l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left  = build(vals, l, mid - 1);
        node->right = build(vals, mid + 1, r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, (int)vals.size() - 1);
    }
};