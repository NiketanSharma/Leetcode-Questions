// Approach:
// This approach uses recursive binary search on a Binary Search Tree (BST). 
// Starting from the root, the function compares the target value with the current node’s value. 
// If they match, it returns that node. If the target is smaller, it recursively searches in the left subtree; 
// if larger, it searches in the right subtree. Because a BST maintains ordered structure (left < root < right), this eliminates half the tree at each step, making the search efficient with time complexity proportional to the tree height (O(h)).
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)return nullptr;
        if(root->val == val)return root;
        if(val<root->val){
            return searchBST(root->left,val);
        }else if(val>root->val){
            return searchBST(root->right,val);
        }
        return nullptr;
    }
};