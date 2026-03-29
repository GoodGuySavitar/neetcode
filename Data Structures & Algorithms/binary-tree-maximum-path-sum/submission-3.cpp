/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/19ce1187-387e-4323-f2c9-1a317ab36200/public$0
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    int dfs(TreeNode* root, int& maxi){
        if(!root) return 0;

        int leftMax = max(dfs(root->left, maxi), 0);
        int rightMax = max(dfs(root->right, maxi), 0);

        maxi = max(maxi, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        dfs(root, maxi);
        return maxi;
    }
};
