class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> picks(nums.size(), false);
        vector<int> sub;
        dfs(nums, sub, picks);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& sub, vector<bool>& picks){
        if(sub.size() == nums.size()){
            ans.push_back(sub);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(!picks[i]){
                sub.push_back(nums[i]);
                picks[i] = true;
                dfs(nums, sub, picks);
                sub.pop_back();
                picks[i] = false;
            }
        }
    }
};
