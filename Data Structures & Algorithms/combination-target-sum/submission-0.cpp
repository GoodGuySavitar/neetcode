class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        dfs(nums, target, sub, 0);
        return ans;
    }

    void dfs(vector<int>& nums,int target,vector<int>& sub, int i){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        else if(target < 0 || i >=nums.size()){
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, target-nums[i], sub, i);  //CALL IT WITHOUT CHANGING INDEX AND CHANGING TARGET
        sub.pop_back();
        dfs(nums, target, sub, i + 1);      //CALL IT WITHOUT CHANGING TARGET AND CHANGING INDEX
    }
};
