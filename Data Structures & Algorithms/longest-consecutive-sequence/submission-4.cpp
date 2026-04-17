class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> mapp;
        for(int i = 0; i < nums.size(); ++i){
            mapp[nums[i]] = i;
        }

        int l = 1;
        int cl = 1;
        for(int n : nums){
            int curr = n;
            while(mapp.find(curr + 1) != mapp.end()){
                cl++;
                curr++;
            }
            l = max(l, cl);
            cl = 1;
        }

        return l;
    }
};
