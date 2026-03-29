class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto& n : nums){
            count[n]++;
        }

        for(const auto& num : count){
            bucket[num.second].push_back(num.first);
        }

        vector<int> result;
        for(int i = bucket.size()-1; i >=0; --i){
            for(int n : bucket[i]){
                result.push_back(n);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
