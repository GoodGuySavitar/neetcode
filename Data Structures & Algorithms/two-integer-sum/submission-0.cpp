class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mapp;
        for(int i = n-1; i >= 0; --i)
        {
            res = target - nums[i];
            if(mapp.find(res) != mapp.end())
            {
                return {i, mapp[res]};
            }
            mapp[nums[i]] = i;
        }
        return {-1,-1};    
    }
};
