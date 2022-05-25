//
// Created by Jiani Wang on 2021/8/22.
//

// 堆排序法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heapify(nums, nums.size());
        int max_num;
        for(int i = 0; i< k; i++){
            max_num = nums[0];
            swap(nums[0], nums[nums.size()-1-i]);
            ShiftDown(nums, 0, nums.size()-1-i);
        }
        return max_num;
    }
    void Heapify(vector<int>& nums, int heapSize){
        for(int i = heapSize/2-1; i>=0; i--){
            ShiftDown(nums, i, heapSize);
        }
    }
    void ShiftDown(vector<int> & nums, int i, int heapSize){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        while(left < heapSize){
            int ptr = left;
            if(right < heapSize && nums[ptr] < nums[right])
                ptr++;
            if(nums[i] > nums[ptr]){
                break;
            }
            swap(nums[i], nums[ptr]);
            i = ptr;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }
};
