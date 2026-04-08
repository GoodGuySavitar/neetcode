class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = 0; 
        int count = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(count == 0){
                curr = nums[i];
            }

            count += (nums[i] == curr) ? 1 : -1;
        }

        count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == curr){
                count++;
            }
        }
        if(count > nums.size()/2){
            return curr;
        }
        return -1;
    }
};