//
// Created by Jiani Wang on 2021/8/19.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1; // [0..zero] is 0
        int two = nums.size();  // [two... nums.size()-1] is two
        int i = 0;
        while(i < two){
            if(nums[i] == 0){
                //zero指针至少比i小1，所以不担心越界问题
                swap(nums[i], nums[zero+1]);
                zero++;
                i++;
            }
            else if(nums[i] == 1){
                i++;
            }
            else{ // nums[i] == 2
                two--;
                swap(nums[i], nums[two]);
                // i do not add
            }
        }
    }
};