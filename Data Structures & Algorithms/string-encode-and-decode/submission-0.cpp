class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(string& str : strs){
            enc += to_string(str.size()) + '#' + str  ;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + length;
            strs.push_back(s.substr(i, length));
            i = j;
        }
        return strs;
    }
};
