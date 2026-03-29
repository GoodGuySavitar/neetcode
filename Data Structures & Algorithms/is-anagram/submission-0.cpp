class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mapp;
        for(int i = 0; i < n; ++i){
            mapp[s[i]]++;
        }
        for(int i = 0; i < m; ++i){
            if(mapp.find(t[i]) == mapp.end() || mapp[t[i]] == 0){
                return false;
            }
            else {
                mapp[t[i]]--;
            }
        }
        return true;
    }
};
