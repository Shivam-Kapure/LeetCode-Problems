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
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftSubtree = max(dfs(root->left), 0);
        int rightSubtree = max(dfs(root->right), 0);

        int sum = root->val + leftSubtree + rightSubtree;
        maxSum = max(maxSum, sum);
        return root->val + max(leftSubtree, rightSubtree);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};