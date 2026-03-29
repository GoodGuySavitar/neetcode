class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int ans = 1;
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n-1; ++i){
            if(nums[i+1] - nums[i] == 1){
                count++;
            }
            else if(nums[i+1] == nums[i]) continue;
            else {
                count = 1;
            } 
            ans = max(count, ans);  
        }
        return ans;
    }
};
