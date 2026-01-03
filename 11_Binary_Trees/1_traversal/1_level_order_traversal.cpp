
/*

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

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
    void bfs(TreeNode* root , vector<vector<int>> &ans){
        if(!root) return;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);
        vector<int> arr;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            if(top == NULL){
                ans.push_back(arr);
                arr.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                arr.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root , ans);
        return ans;
    }
};