class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergesort(vector<int>& nums , int left, int right){
        if(left >= right) return;
        int mid = (right+left) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums , int left, int mid , int right){
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else if(nums[j] < nums[i]){
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= right){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = left; i <= right; i++){
            nums[i] = temp[i - left];
        }

    }
};