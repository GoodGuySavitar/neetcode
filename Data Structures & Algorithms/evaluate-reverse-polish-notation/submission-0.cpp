class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i = 0; i < n; ++i){
            if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens.size() > 1 && 
            isdigit(tokens[i][1]))){
                st.push(stoi(tokens[i]));
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    int c = b + a;
                    st.push(c);
                }
                else if(tokens[i] == "-"){
                    int c = b - a;
                    st.push(c);
                }
                else if(tokens[i] == "*"){
                    int c = b * a;
                    st.push(c);
                }
                else if(tokens[i] == "/"){
                    int c = b / a;
                    st.push(c);
                }
            }
        }

        return st.top();
    }
};
