class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int lm = 0;
       int rm = 0;
       int curr = 0;
       int l = 0;
       int r = n-1; 
       while (l < r){
            if(height[l] <= height[r]){
                if(lm > height[l]){
                    curr+= lm-height[l];
                }
                else {
                    lm = height[l];
                }
                l++;
            }
            else {
                if(rm > height[r]){
                    curr += rm-height[r];
                }
                else{
                    rm = height[r];
                }
                r--;
            }
       }
        return curr;
    }
};
