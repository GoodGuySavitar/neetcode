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
private: 
    pair<int, bool> dfs(TreeNode* root, bool& ans){
        if(!root) return {0, true};
        if(ans == true){
            pair<int, bool> left = dfs(root->left, ans);
            pair<int, bool> right = dfs(root->right, ans);

            if(left.first - right.first > 1 || right.first - left.first > 1){
                ans = false;
            }
            return {1+max(left.first, right.first), ans};
        }
        else{
            return{0, false};
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ans = true;
        pair<int, bool> anss = dfs(root, ans);
        if(anss.second == true) return true;
        return false;
    }   
};
