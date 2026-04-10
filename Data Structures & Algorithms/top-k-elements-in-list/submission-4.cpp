class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        vector<vector<int>> freq(nums.size() + 1); 

        for(int i = 0; i < nums.size(); ++i){
            mapp[nums[i]]++;
        }

        for(const auto& pair : mapp){
            freq[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        for(int i = freq.size() - 1; i > 0; --i){
            for(int n : freq[i]) {
                ans.push_back(n);
                if(ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};
