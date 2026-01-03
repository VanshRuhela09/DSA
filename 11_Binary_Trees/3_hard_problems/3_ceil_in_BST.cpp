/*

*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        while(root){
            if(x == root->data){
                return x;
            }
            else if(root->data > x){
                ans = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ans;
    }
};