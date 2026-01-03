/*

*/
class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        // Map stores: horizontal distance (line) -> node value
        // We use map to ensure left-to-right sorting based on line.
        map<int, int> mpp; 
        
        // Queue for BFS traversal: {Node*, horizontal_distance (line)}
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            // For Bottom View, we simply overwrite the map entry every time
            // we encounter a node at a particular line. 
            // The last node encountered (which is the lowest one in BFS) 
            // for that line will be the one that remains visible from the bottom.
            mpp[line] = node->data;
            
            if (node->left != NULL) {
                // Left child moves one unit left (line - 1)
                q.push({node->left, line - 1});
            }
            
            if (node->right != NULL) {
                // Right child moves one unit right (line + 1)
                q.push({node->right, line + 1});
            }
        }
        
        // Iterate through the map. Since std::map is sorted by key (the line),
        // the nodes are automatically added to 'ans' from left-to-right.
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};