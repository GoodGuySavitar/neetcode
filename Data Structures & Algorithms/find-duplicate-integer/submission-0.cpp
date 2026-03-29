class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mapp;

        for(int i = 0; i < n; ++i){
            if(mapp.find(nums[i]) != mapp.end()){
                return nums[i];
            }
            mapp[nums[i]]++;
        }

        return 0;
    }
};