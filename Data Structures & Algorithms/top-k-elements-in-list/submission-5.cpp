class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for(int i = 0; i < nums.size(); ++i){
            mapp[nums[i]]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(const auto& pair : mapp){
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        for(int i = bucket.size() - 1; i > 0; --i){
            for(int n : bucket[i]){
                ans.push_back(n);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
