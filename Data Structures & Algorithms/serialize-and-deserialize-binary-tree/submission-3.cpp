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

    class Codec {
    private: 
        void preorder(TreeNode* root, string& s){
            if(!root){
                s += "N#";
                return;
            };
            s += to_string(root->val) + "#";
            preorder(root->left, s);
            preorder(root->right, s);
        }

        TreeNode* dfs(vector<string>& pre, int& i){
            if(pre[i] == "N"){
                i++;
                return nullptr;
            }

            TreeNode* root = new TreeNode(stoi(pre[i]));
            i++;
            root->left = dfs(pre, i);
            root->right = dfs(pre, i);
            return root;
        }
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string s = "";
            preorder(root, s);
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            vector<string> pre; 
            
            for(int i = 0; i < data.size(); ++i){
                string s = "";
                while(data[i] != '#'){
                    s+=data[i];
                    i++;
                }
                if(s!="") pre.push_back(s);
            }

            int i = 0;
            return dfs(pre, i);       
        }   
    };
