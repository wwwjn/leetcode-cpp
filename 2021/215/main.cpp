#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size()-1, k);
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
    int partition(vector<int>&nums, int left, int right) {
        int i = left;
        int j = right;
        int pivotNum = nums[left];
        while(i != j){
            while(i<j && nums[j] <= pivotNum) j--;
            if(i<j) nums[i] = nums[j];
            while(i<j && nums[i] > pivotNum) i++;
            if(i<j) nums[j] = nums[i];
        }
        nums[i] = pivotNum;
        return i;
    }
};

int main() {
    //nums = [3,2,3,1,2,4,5,5,6], k = 4
    int arr[] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    cout << Solution().findKthLargest(nums, k);
    return 0;
}
