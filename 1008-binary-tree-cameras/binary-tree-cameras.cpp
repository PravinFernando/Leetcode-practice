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
    int ans;
    unordered_set<TreeNode*> covered;

    int minCameraCover(TreeNode* root) {
        ans = 0;
        covered.insert(nullptr);  // None equivalent in Python
        dfs(root, nullptr);
        return ans;
    }

    void dfs(TreeNode* node, TreeNode* parent) {
        if (node) {
            dfs(node->left, node);
            dfs(node->right, node);

            if ((parent == nullptr && covered.find(node) == covered.end()) ||
                covered.find(node->left) == covered.end() ||
                covered.find(node->right) == covered.end()) {
                
                ans++;
                covered.insert(node);
                covered.insert(parent);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
    }
};
