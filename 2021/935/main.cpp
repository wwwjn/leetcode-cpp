#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    unordered_map<int, vector<int>> record;  // digit ->
    vector<vector<int>> dp;  // i,j : how much number do we have ends with digit 'j' when n = i;
public:
    int knightDialer(int n) {
        record.insert({1, {8, 6}});
        record.insert({2, {7, 9}});
        record.insert({3, {4, 8}});
        record.insert({4, {0, 3, 9}});
        record.insert({5, {}});
        record.insert({6, {0, 1, 7}});
        record.insert({7, {2, 6}});
        record.insert({8, {1, 3}});
        record.insert({9, {2, 4}});
        record.insert({0, {4, 6}});

        dp = vector<vector<int>>(n, vector<int>(10, 0));

        // n = 1;
        for(int i = 0; i <= 9; i++){
            dp[0][i] = 1;
        }
        int modNum = 1000000007;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 9; j++){
                vector<int>& nextStep = record[j];
                int count = dp[i-1][j]; // how many times the digit appears
                for(int k = 0; k < nextStep.size(); k++){
                    int next = nextStep[k];
                    dp[i][next] = ((dp[i][next] % modNum) + (dp[i-1][j] % modNum)) % modNum;
                }
            }
        }
        int res = 0;

        for(int i = 0; i <= 9; i++){
            res = ((res % modNum) + (dp[n-1][i] % modNum)) % modNum;
        }
        return res;
    }
};