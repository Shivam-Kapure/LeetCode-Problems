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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfsHelper(root, path, targetSum);
        return res;
    }

    void dfsHelper(TreeNode* root, vector<int>& path, int newTarget) {
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        newTarget -= root->val;

        if(root->left == nullptr && root->right == nullptr) {
            if(newTarget == 0)
                res.push_back(path);
        }
        else {
            dfsHelper(root->left, path, newTarget);
            dfsHelper(root->right, path, newTarget);
        }
        path.pop_back();
    }
};