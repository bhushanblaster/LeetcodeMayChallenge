/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

*/
/*
Approach:

Inorder traversal gives the BST elements in increasing order.
Hence traverse inorder and stop at Kth element.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int& k,int& ans)
    {
            if(!root)
            return;
            traverse(root->left,k,ans);
            k--;
            if(k==0)
            {
                ans = root->val;
                return;
            }
            traverse(root->right,k,ans);
                
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        traverse(root,k,ans);
        return ans;
    }
};
