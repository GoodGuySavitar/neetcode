class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> arr;
        stack<pair<int, int>> st;

        int n = position.size();
        int ans = 0;

        for(int i = 0; i < n; ++i){
            arr.push_back({position[i], speed[i]});
        }
        
        sort(arr.begin(), arr.end());

        for(int i = n-1; i >= 0; --i){
            if(st.empty()){
                st.push({arr[i].first, arr[i].second});
            }
            else{
                double time = (double)(target - st.top().first)/st.top().second;
                st.push({arr[i].first, arr[i].second});
                double currTime = (double)(target - st.top().first)/st.top().second;
                if(currTime <= time){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }

        return ans;
    }
};