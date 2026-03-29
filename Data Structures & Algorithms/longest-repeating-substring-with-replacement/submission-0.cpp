class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0, maxf = 0;
        int maxi = 1;
        int mapp[26] = {0};

        while(r < s.length()){
            mapp[s[r] - 'A']++;
            maxf = max(maxf, mapp[s[r] - 'A']);

            while((r-l+1) - maxf > k){
                mapp[s[l] - 'A']--;
                maxf = 0; 

                for(int i = 0; i < 26; ++i){
                    maxf = max(maxf, mapp[i]);
                }
                l++;
            }

            if((r-l+1) - maxf <= k){
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};
