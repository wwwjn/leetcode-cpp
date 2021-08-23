//
// Created by Jiani Wang on 2021/8/22.
//


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0; //[i...j)
        int j = 0;
        int min_len = nums.size() + 1;
        int sum = 0;
        while(j < nums.size()){
            if(sum < target){
                sum += nums[j];
                j++;
            }
            if(sum >= target){
                while(sum - nums[i] >= target){
                    sum -= nums[i];
                    i++;
                }
                min_len = min(min_len, j-i);
                // move i or move j
                if(j == i){ // [i, j) is empty
                    sum += nums[j];
                    j++;
                }
                else{
                    sum -= nums[i];
                    i++;
                }
            }
        }
        return min_len == nums.size() +1 ? 0: min_len;
    }
};