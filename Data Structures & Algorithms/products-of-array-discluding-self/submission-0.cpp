class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;
        int zeros = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0) {
                zeros++;
            }
            else mul *= nums[i];
        }

        if(zeros > 1){
           return vector<int>(nums.size(), 0);
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(zeros > 0 && nums[i] != 0){
                ans.push_back(0);
            }
            else if (nums[i] == 0) {
                ans.push_back(mul);
            }
            else ans.push_back(mul/nums[i]);
        }
        return ans;
    }
};
