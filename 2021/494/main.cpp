#include <iostream>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int n = (sum + target) /2;
        if(n < 0 || (sum + target) %2 != 0){
            return 0; // impossible
        }
        // 选一些元素，和为new_t 有几种方法
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        memo[0][0] = 1;  // 重要
        // for(int i = 1; i <= n; i++){
        //     // 用nums[0] 填满
        //     if(nums[0] == i)
        //         memo[0][i] = 1;
        // }
        if(m == 0){
            return 1;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= n; j++){
                memo[i][j] = memo[i-1][j]; // 不选nums[i]
                if(j >= nums[i-1])
                    memo[i][j] += memo[i-1][j-nums[i-1]];
            }
        }
        return memo[m][n];
    }
        int findTargetSumWays2(vector<int>& nums, int S) {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
                sum += nums[i];
            if (S > sum) return 0; // 此时没有方案
            if((S+sum)%2==1) return 0;// 此时没有方案
            int bagSize = (S + sum) / 2;
            vector<int> dp(bagSize + 1, 0);
            dp[0] = 1;
            cout << dp[0] << " " << dp[1] << endl;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = bagSize; j >= nums[i]; j--) {
                    dp[j] += dp[j - nums[i]];
                }
                cout << dp[0] << " " << dp[1] << endl;
            }
        return dp[bagSize];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
