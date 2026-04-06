class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mapp;

        for(int i = 0; i < strs.size(); i++){
            vector<int> curr(26, 0);
            for(int j = 0; j < strs[i].size(); j++){
                curr[strs[i][j] - 'a']++;
            }
            string key = to_string(curr[0]);
            for(int k = 1; k < 26; k++){
                key += ',' + to_string(curr[k]);
            }

            mapp[key].push_back(strs[i]);
        }

        for(const auto& pair: mapp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};

