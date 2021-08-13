#include <iostream>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo = vector<int>(n, 0);
        // memo[i]: rob from [0...i] get the money number;
        // house number [0....n-1];
        memo[0] = nums[0];
        if(n == 1){
            return memo[0];
        }
        memo[1] = max(nums[0], nums[1]);
        if(n == 2){
            return memo[1];
        }

        for(int i = 2; i < n-1; i++){  //rob from [0...n-2]
            // 情况1: i-1抢， i不抢；
            // 情况2: i-2抢， i-1不抢，i抢
            memo[i] = max(memo[i-1], memo[i-2]+nums[i]);
        }

        vector<int> memo2 = vector<int>(n, 0);
        memo2[1] = nums[1];
        memo2[2] = max(nums[1], nums[2]);
        for(int i = 3; i < n; i++){  // considering rob from house [1.. n-1]
            // 情况1: i-1抢， i不抢；
            // 情况2: i-2抢， i-1不抢，i抢
            memo2[i] = max(memo2[i-1], memo2[i-2]+nums[i]);
        }
        return max(memo[n-2], memo2[n-1]);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
