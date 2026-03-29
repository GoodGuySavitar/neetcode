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
    bool dfs(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        else if(!p || !q){
            return false;
        }

        bool left = dfs(p->left, q->left);
        bool right = dfs(p->right, q->right);

        if(left == true && right == true && p->val == q->val) return true;
        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        else if(!p || !q){
            return false;
        }
        return dfs(p,q);
    }
};
