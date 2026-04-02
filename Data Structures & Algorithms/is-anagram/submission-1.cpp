class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int, int> mapp(s.size());
        for(int i = 0; i < s.size(); i++){
            mapp[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++){
            if(mapp.find(t[i]) == mapp.end()){
                return false;
            }
            if(mapp[t[i]] > 1){
                mapp[t[i]]--;
            }
            else{
                mapp.erase(t[i]);
            }
        }

        if(mapp.empty()) return true;

        return false;
    }
};
