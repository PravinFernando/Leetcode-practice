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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        unordered_map<int, vector<int>> cols; // column -> all values
        queue<pair<TreeNode*, int>> q;        // node, column index
        q.push({root, 0});

        while (!q.empty()) {
            unordered_map<int, vector<int>> curCols; // store current level’s values

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, col] = q.front();
                q.pop();

                curCols[col].push_back(node->val);

                if (node->left)  q.push({node->left,  col - 1});
                if (node->right) q.push({node->right, col + 1});
            }

            // For each column at this level, sort before merging
            for (auto &p : curCols) {
                sort(p.second.begin(), p.second.end());
                for (int val : p.second)
                    cols[p.first].push_back(val);
            }
        }

        // Collect columns in sorted order of column index
        vector<int> keys;
        for (auto &p : cols)
            keys.push_back(p.first);
        sort(keys.begin(), keys.end());

        vector<vector<int>> result;
        for (int k : keys)
            result.push_back(cols[k]);

        return result;
    }
};
