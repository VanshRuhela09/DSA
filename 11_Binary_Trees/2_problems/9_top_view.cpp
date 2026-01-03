/*

*/

class Solution {
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        // Map stores: horizontal distance (line) -> node value
        // The first node encountered at a given line distance is the one visible from the top.
        map<int, int> mpp; 
        
        // Queue for BFS traversal: {Node*, horizontal_distance (line)}
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            // If the map does NOT contain this horizontal distance (line), 
            // it means this is the first node encountered for this line, so it's visible.
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
            
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