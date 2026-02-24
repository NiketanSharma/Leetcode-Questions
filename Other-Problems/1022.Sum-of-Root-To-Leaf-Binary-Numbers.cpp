// Approach:
// In this solution, you traverse the tree from root to leaf while maintaining a running value x that represents the binary number formed so far. 
// At each node, you update the value using:
// x = x * 2 + root->val
// This simulates left-shifting the binary number (multiply by 2) and adding the current node’s bit (0 or 1).
// When you reach a leaf node (root->left == root->right), the formed binary number is complete, so you return its decimal value.
// Finally, you recursively compute the sum of values from the left and right subtrees and return their total.
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
    int sumRootToLeaf(TreeNode* root) {
        return DFS(root,0);
    }
    int DFS(TreeNode* root, int x){
        if(root == nullptr)return 0;
        x = x * 2 + root->val;
        if(root->left == root->right)return x;
        return DFS(root->left,x)+DFS(root->right,x);
    }
};