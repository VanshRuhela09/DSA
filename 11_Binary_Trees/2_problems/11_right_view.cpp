class Solution {
public:
    // Helper function for recursive traversal
    void recursion(TreeNode *root, int level, vector<int> &res) {
        if (root == NULL) return;

        // If the size of the result vector equals the current level, 
        // it means we are seeing the first node at this level, which is 
        // guaranteed to be the right-most node because we start traversal 
        // from the right child.
        if (res.size() == level) {
            res.push_back(root->val);
        }

        // 1. Traverse Right Child First: This is the key step.
        recursion(root->right, level + 1, res);

        // 2. Then traverse Left Child
        recursion(root->left, level + 1, res);
    }

    // Main function to return the Right Side View
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res); // Start at level 0
        return res;
    }
};