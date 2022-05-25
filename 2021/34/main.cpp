#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //find first
        int left = searchLeft(nums, target, 0, nums.size()-1);
        int right = searchRight(nums, target, 0, nums.size()-1);
        vector<int> tmp;
        tmp.push_back(left);
        tmp.push_back(right);
        return tmp;
    }
    int searchLeft(vector<int>& nums, int target, int start, int end){
        // search from [left... end]
        int l = start;
        int r = end;
        int left = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] == target){
                left = mid;
                r = mid - 1;
            }else{
                r = mid - 1;
            }
        }
        return left;
    }
    int searchRight(vector<int>& nums, int target, int start, int end){
        // search from [left... end]
        int l = start;
        int r = end;
        int right = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] == target){
                right = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return right;
    }
};