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
    int maxi(TreeNode* root){
        if(!root) return 0;

        int left = maxi(root->left); 
        int right = maxi(root->right);

        int count = max(left, right);
        return count + 1;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return maxi(root);
    } 
};
