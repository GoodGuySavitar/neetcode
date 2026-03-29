class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> sub;
        dfs(s, sub, 0, 0);
        return ans;
    }

    void dfs(string& s, vector<string>& sub, int i, int j){
        if(j >= s.length()){
            if(i == j){
                ans.push_back(sub);
                return;
            }
            return;
        }

        if(isPalindrome(s, i, j)){
            sub.push_back(s.substr(i, j - i + 1));
            dfs(s, sub, j + 1, j + 1);
            sub.pop_back();
        }

        dfs(s, sub, i, j + 1);
    }
    

    
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};


