class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    int partition(vector<int>& nums, int left, int right){
        // partition [left, right]
        if(left >= right) return -1;
        int pivot = nums[left], l = left + 1, r = right;
        while(l <= r){
            if(nums[l] < pivot) l++;  // [left+1, l) > pivot
            else if(nums[r] >= pivot) r--;  // (r, right] >= pivot
            else{
                swap(nums[l++], nums[r--]);
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    void quickSort(vector<int>& nums, int low, int high){
        // cout << low << " " << high << endl;
        if (low >= high) return;  // sorted
        // randomize
        swap(nums[low + rand() % (high - low + 1)], nums[low]);
        int pivot = partition(nums, low, high);
        // cout << pivot << endl;
        quickSort(nums, low, pivot);
        quickSort(nums, pivot+1, high);
    }
};