#include <iostream>

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 贪心算法
        int n = nums.size();
        if(nums.size() == 1){
            return 1;
        }
        int prevdiff = nums[1] - nums[0];
        int res = (prevdiff == 0) ? 1: 2;  // 如果prevdiff == 0，就只能选一个
        for(int i = 2; i < nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            if((diff < 0 && prevdiff >= 0) || (diff > 0 && prevdiff <= 0)){
                res ++;  // 选择i进入
                prevdiff = diff;
            }else
                continue;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
