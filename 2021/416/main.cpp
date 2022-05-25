#include <iostream>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
        }
        int bag_size = sum/2;
        if(sum % 2 != 0){
            return false;
        }
        vector<bool> memo = vector<bool>(bag_size+1, false);
        // 填写边界
        for(int i = 0; i <= bag_size; i++){
            if(i == nums[0])
                memo[i] = true;
            else
                memo[i] == false;
        }

        // 填写其他部分
        for(int i = 1; i< n; i++){
            //[0...i]的元素是否能正好填充背包容量为j的背包
            for(int j = bag_size; j >= nums[i] ; j--){
                memo[j] = memo[j] || memo[j-nums[i]];
            }
        }
        return memo[bag_size];

    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
