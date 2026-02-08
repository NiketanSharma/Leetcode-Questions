// Approach:
// This approach checks whether a binary tree is height-balanced using a bottom-up DFS traversal. 
// The helper function recursively computes the height of each subtree while simultaneously verifying balance. 
// For every node, it gets the heights of the left and right subtrees; if their difference is greater than 1, it returns -1 to signal that the tree is unbalanced. 
// This -1 value is propagated upward to stop further unnecessary computation. If both subtrees are balanced, it returns the current node’s height as 1 + max(leftHeight, rightHeight). 
// The main function simply checks whether the final result is -1 or not. This method runs in O(n) time since each node is visited once.
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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = dfsHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }
};