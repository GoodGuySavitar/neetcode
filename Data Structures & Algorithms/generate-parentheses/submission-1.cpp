class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) { 
        string sub;
        dfs(n, sub, 0, 0);
        return ans;
    }

    void dfs(int n, string& sub, int open, int close){
        if(open == close && open == n){
            ans.push_back(sub);
            return;
        }

        if(open < n){
            sub.push_back('(');
            dfs(n, sub, open + 1, close);
            sub.pop_back();
        }    

        if(close < open){
            sub.push_back(')');
            dfs(n, sub, open, close + 1);
            sub.pop_back();
        }    
    }
};