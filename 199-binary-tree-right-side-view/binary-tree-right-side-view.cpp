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
    void reversePreOrder(TreeNode* root, int level, vector<int>& result) {
        if(root == NULL)
            return;
        if(level == result.size())
            result.push_back(root->val);

        reversePreOrder(root->right, level + 1, result);
        reversePreOrder(root->left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        reversePreOrder(root, level, result);
        return result;
    }
};