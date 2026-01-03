/*
Given a binary tree, determine if it is height-balanced.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
*/


//NAIVE SOLUTION
bool check(Node* node) {
    if (node == NULL)
        return true;

    int lh = findHLeft(node->left);
    int rh = findHRight(node->right);

    if (abs(rh - lh) > 1)
        return false;

    bool left = check(node->left);
    bool right = check(node->right);

    if (!left || !right)
        return false;

    return true;
}


//O(N) solution
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};
