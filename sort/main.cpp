#include <iostream>
#include <vector>


// lc912
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums){

    }
    void quicksort(vector<int>& nums, int left, int right){
        if(left >= right){  // the end of quick sort
            return;
        }
        //sort [left...right]
        selectPivot(nums, left, right);
        int k = partition(nums, left, right);
        quicksort(nums, k+1, right);
        quicksort(nums, left, k-1);
    }

private:
    void selectPivot(vector<int>& nums, int left, int right){
        swap(nums[left], nums[(left+right)/2]);
    }
    int partition(vector<int>& nums, int left, int right){
        int i = left;
        int j = right;
        int PivotNum = nums[left];  // find a vacant slot
        while(i != j){
            while(j>i && nums[j] > PivotNum) j--;
            if(j>i) nums[i] = nums[j];
            while(j>i && nums[i] <= PivotNum) i++;
            if(j>i) nums[j] = nums[i];
        }
        nums[i] = PivotNum;
        return i;
    }
    int partition2(vector<int>& nums, int left, int right){
        // [left...l) < pivot
        int l = left + 1; // the item is being considered
        int r = right;  //(r...right] > pivot
        int PivotNum = nums[left];
        while(l <= r){
            if(nums[l] <= PivotNum){
                l++;
            }else{
                swap(nums[r--], nums[l]);
            }
        }
        swap(nums[left], nums[l-1]);
        return l-1;
    }
};



int main() {
    int arr[] = {5,1,1,2,0,0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> nums2;
    for(int k = 0; k <= 50000; k++){
        nums2.push_back(k);
    }
    Solution().quicksort(nums2, 0, nums2.size()-1);

    for(int k = 0; k < nums2.size(); k++){
        cout << nums2[k] << ",";
    }
    return 0;
}
