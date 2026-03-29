class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, sub, target, 0, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<int>& sub, int& target, int total, int i){
        if(total == target){
            ans.push_back(sub);
            return;
        }
        else if (total > target || i >= candidates.size()){
            return; 
        }
        
        sub.push_back(candidates[i]);
        dfs(candidates, sub, target, total + candidates[i], i + 1);
        sub.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        dfs(candidates, sub, target, total, i + 1);
    }
};
