class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapp;

        for(auto& s : strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; ++i){
                key += ',' + count[i];
            }

            mapp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(const auto pair : mapp){
            result.push_back(pair.second);
        }

        return result;
    }
};
