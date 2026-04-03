class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string first = strs[0];
        for(int i = 0; i < n; i++){
            string curr;
            for(int j = 0; j < first.size(); j++){
                if(first[j] == strs[i][j]){
                    curr += strs[i][j];
                    continue;
                }
                else{
                    first = curr;
                    break;
                }
            }
        }
        return first;
    }
};