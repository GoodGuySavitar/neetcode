class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;
        int res;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            res = target - nums[i];
            if(mapp.find(res) != mapp.end()){
                if(mapp[res] < i){
                    ans.push_back(mapp[res]);
                    ans.push_back(i);
                }
                else{
                    ans.push_back(i);
                    ans.push_back(mapp[res]);
                }
            }
            mapp[nums[i]] = i;
        }
        
        return ans;
    }
};