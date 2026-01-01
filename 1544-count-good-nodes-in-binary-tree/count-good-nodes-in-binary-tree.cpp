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
    void getGoodNodes(TreeNode* root, int& goodCount, int maxSoFar) {
        if(root == NULL)
            return;
        if(root->val >= maxSoFar)
            goodCount++;
        maxSoFar = max(root->val, maxSoFar);

        getGoodNodes(root->left, goodCount, maxSoFar);
        getGoodNodes(root->right, goodCount, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        int goodCount = 0;
        getGoodNodes(root, goodCount, root->val);
        return goodCount;
    }
};