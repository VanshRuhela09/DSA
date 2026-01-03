/*

*/

class Solution {
public:
    // Main function to check for symmetry
    bool isSymmetric(TreeNode* root) {
        // A null tree is considered symmetric. Start the comparison from the root's children.
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
    
private:
    // Helper function to compare two subtrees for mirroring properties
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        
        // Case 1: If both nodes are NULL, they are symmetric.
        // Case 2: If one node is NULL and the other is not, they are NOT symmetric.
        // Since left and right are boolean expressions, left == right handles both cases:
        // (true == true) -> true (both NULL)
        // (false == false) -> true (both NOT NULL - handled below)
        // (true == false) -> false (one NULL, one NOT NULL)
        if (left == NULL || right == NULL) {
            return left == right;
        }

        // Case 3: If both nodes are NOT NULL, check their values.
        if (left->val != right->val) {
            return false;
        }

        // Case 4: The core recursive check for mirroring:
        // Compare the left's LEFT child with the right's RIGHT child (Outer Pair).
        // AND
        // Compare the left's RIGHT child with the right's LEFT child (Inner Pair).
        return isSymmetricHelp(left->left, right->right)
            && isSymmetricHelp(left->right, right->left);
    }
};