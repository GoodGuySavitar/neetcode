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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, arr);
        int ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; ++i){
            ans = arr[i];
        }
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& arr){
        if(!root) return;

        dfs(root->left, arr);
        dfs(root->right, arr);

        arr.push_back(root->val);
    }
};
