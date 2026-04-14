class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }   

    void quicksort(vector<int>& nums, int low, int high){
        if(low < high){
            int pi = partition(nums, low, high);
            quicksort(nums, low, pi-1);
            quicksort(nums, pi+1, high);
        }
    }
    
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i < j){
            while(nums[i] <= pivot && i <= high - 1){
                i++;
            }
            while(nums[j] > pivot && j >= low + 1){
                j--;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[low], nums[j]);
        return j;
    }

};  