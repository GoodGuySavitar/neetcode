class Solution {
public:
    vector<string> mapp = {"" , "", "abc", "def", "ghi", "jkl", "mno", 
    "pqrs", "tuv", "wxyz"};
    vector<string> ans; 
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string sub;
        dfs(digits, sub, 0);
        return ans;
    }

    void dfs(string& digits, string sub, int i){
        if(sub.size() == digits.size()){
            ans.push_back(sub);
            return;
        }

        string choices = mapp[digits[i] - '0'];
        for(char c : choices){
            dfs(digits, sub + c, i + 1);
        }
    }
};
