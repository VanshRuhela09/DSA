class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes: x-coordinate -> (y-coordinate -> multiset of values)
        map<int, map<int, multiset<int>>> nodes;
        // Queue for BFS: {TreeNode*, {x-coordinate, y-coordinate}}
        queue<pair<TreeNode*, pair<int, int>>> todo; 

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first; // Vertical index (column)
            int y = p.second.second; // Level index (row/depth)

            nodes[x][y].insert(node->val);

            if (node->left) {
                // Left child moves one column left (x-1) and one level down (y+1)
                todo.push({node->left, {x - 1, y + 1}});
            }

            if (node->right) {
                // Right child moves one column right (x+1) and one level down (y+1)
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        // Iterate through the map, which is sorted by the vertical index 'x'
        for (auto p : nodes) {
            vector<int> col;
            // Iterate through the inner map, which is sorted by the level index 'y'
            for (auto q : p.second) {
                // Insert all elements from the multiset (which handles same-level, same-column sorting)
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};