class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;

        unordered_map<char, int> mapp;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < n){
            if(mapp.find(s[r]) == mapp.end()){
                mapp[s[r]]++;
                r++;
            }
            else{
                ans = max(ans, r-l);
                while(s[l] != s[r]){
                    mapp.erase(s[l]);
                    l++;
                }
                l++;
                r++;
            }
        }
        ans = max(ans, r-l);
        return ans;
    }
};
