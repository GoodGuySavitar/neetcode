class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) { 
        string sub;
        dfs(n, sub);
        return ans;
    }

    void dfs(int n, string& sub){
        if(sub.length() == n * 2 && validate(sub)){
            ans.push_back(sub);
            return;
        }
        else if(sub.length() == n * 2){
            return;
        }

        sub.push_back('(');
        dfs(n, sub);
        sub.pop_back();

        sub.push_back(')');
        dfs(n, sub);
        sub.pop_back();
    }


    bool validate(string str){
        stack<char> st;

        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '('){
                st.push(str[i]);
            }
            else if(str[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};