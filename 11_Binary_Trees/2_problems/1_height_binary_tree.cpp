/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
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
    // void dfs(int &ans , int dep , TreeNode* root){
    //     if(root->left == NULL && root->right==NULL){
    //         ans = max(ans,dep);
    //     }
    //     if(root->left){
    //         dfs(ans,dep+1,root->left);
    //     }
    //     if(root->right){
    //         dfs(ans,dep+1,root->right);
    //     }
    // }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lDepth = 0;
        int rDepth = 0;
        if(root->left){
            lDepth = maxDepth(root->left);
        }
        if(root->right){
            rDepth = maxDepth(root->right);
        }
        return max(lDepth , rDepth)+1;
        // int ans = 1;
        // dfs(ans,1,root);
        // return ans;
    }
};