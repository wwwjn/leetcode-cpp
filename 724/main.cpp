#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);

        int rightSum = 0;
        for(int i=nums.size()-1; i>=0; i--){
            right[i] = rightSum;

            rightSum += nums[i];
        }
        int leftSum = 0;
        for(int i = 0; i<nums.size(); i++){
            left[i] = leftSum;
            if(right[i] == left[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};