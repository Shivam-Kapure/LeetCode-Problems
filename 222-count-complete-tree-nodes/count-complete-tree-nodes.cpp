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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* l = root;
        TreeNode* r = root;
        int h_left = 0; int h_right = 0;

        while(l != NULL) {
            h_left++;
            l = l->left;
        }
        while(r != NULL) {
            h_right++;
            r = r->right;
        }

        if(h_left == h_right)
            return pow(2, h_right) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};