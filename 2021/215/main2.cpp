//
// Created by Jiani Wang on 2021/8/22.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size()-1, nums.size() - k+1);
    };
    int findKth(vector<int>& nums, int l, int r, int k){
        swap(nums[l], nums[(l + r)/2]);
        int pos = partition(nums, l, r);
        if(pos < k-1){
            return findKth(nums, pos+1, r, k);
        }else if(pos > k-1){
            return findKth(nums, l, pos-1, k);
        }else{
            return nums[pos];
        }
    }

    int partition(vector<int>& nums, int l, int r){
        // partition from nums[l...r];
        // ascending sort
        int pivotNum = nums[l];
        int i = l;
        int j = r;
        while(i != j){
            while(nums[j] > pivotNum && i<j) j--;
            if(i<j) nums[i] = nums[j];
            while(nums[i] <= pivotNum && i<j) i++;
            if(i<j) nums[j] = nums[i];
        }
        nums[i] = pivotNum;
        return i;
    }
};
