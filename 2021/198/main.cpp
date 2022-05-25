#include <iostream>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo = vector<int>(n+1, 0);
        // memo[i]: rob from [1...i] get the money number;
        // house number [1....n];
        memo[0] = 0;
        memo[1] = nums[0];
        if(n == 1){
            return memo[1];
        }
        for(int i = 2; i < n+1; i++){
            // 情况1: i-1抢， i不抢；
            // 情况2: i-2抢， i-1不抢，i抢
            memo[i] = max(memo[i-1], memo[i-2]+nums[i-1]);
        }
        return memo[n];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
