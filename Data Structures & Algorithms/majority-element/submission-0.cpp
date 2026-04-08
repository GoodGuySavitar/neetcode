class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for(int i = 0; i < nums.size(); i++){
            mapp[nums[i]]++;
        }

        for(const auto& pair : mapp){
            if(pair.second > nums.size() / 2){
                return pair.first;
            }
        }

        return -1;
    }
};