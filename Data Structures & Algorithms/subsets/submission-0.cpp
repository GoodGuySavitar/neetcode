class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        dfs(nums, 0, sub, ans);  
        return ans;
    }

    void dfs(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, i+1, sub, ans);
        sub.pop_back();
        dfs(nums, i+1, sub, ans);
    }
};
