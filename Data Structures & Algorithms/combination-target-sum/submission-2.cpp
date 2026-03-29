class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, target, {}, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int target, vector<int> sub, int i, int total){
        if(total == target){
            ans.push_back(sub);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            if(total + nums[j] > target){
                return;
            }
            sub.push_back(nums[j]);
            dfs(nums, target , sub, j, total + nums[j]);
            sub.pop_back();
        }

    }
};
