class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l < r){
            int smaller = min(height[l], height[r]);
            int area = smaller * (r-l);
            ans = max(area, ans);
            if(height[l] <= height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};