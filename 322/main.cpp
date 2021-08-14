#include <iostream>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo = vector<int>(amount+1, amount+1);
        memo[0] = 0;

        for(int j = 1; j <= amount; j++){
            // 用面值为 coins[i] 的硬币去填充 amount = j的背包，正好填充满；
            for(int i = 0; i < coins.size(); i++){
                // coins[i] 不放进去，memo[i][j] = memo[i-1][j];
                // coins[i] 放进去
                if(coins[i] <= j){
                    memo[j] = min(memo[j], memo[j-coins[i]]+1);
                }
            }
        }
        return memo[amount] == amount+1 ? -1: memo[amount];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
