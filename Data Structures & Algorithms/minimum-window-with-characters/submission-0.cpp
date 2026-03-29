class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> mapp1, mapp2;

        for(char c : t){
            mapp1[c]++;
        }

        int curr = 0; 
        int need = mapp1.size();
        int l = 0;
        int resLen = INT_MAX;
        pair<int, int> res= {-1, -1};

        for(int r = 0; r < s.length(); ++r){
            char c = s[r];
            mapp2[c]++;

            if(mapp1.count(c) && mapp1[c] == mapp2[c]){
                curr++;
            }

            while(curr == need){
                if(r - l + 1 < resLen){
                    resLen = r-l+1;
                    res = {l, r};
                }

                mapp2[s[l]]--;

                if(mapp1.count(s[l]) && mapp2[s[l]] < mapp1[s[l]]){
                    curr--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
