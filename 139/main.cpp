#include <iostream>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> record(wordDict.begin(), wordDict.end());
        // dp[j] 表示 s[0..j)是否可以用wordDict中的进行表示
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int j = 1; j <= s.size(); j++){  // 遍历背包容量
            // 划分出所有可能的物品，看物品在不在给定的wordDict中？
            for(int i = 0; i < j; i++){  // 遍历物品
                string temp = s.substr(i, j-i);
                if((dp[i] && record.find(temp) != record.end())){
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
