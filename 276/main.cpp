#include <iostream>

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 1){
            return k;
        }
        vector<int> dp(n, 0);
        dp[0] = k;
        dp[1] = k*k;
        for(int i=2; i<n; i++){
            // ith paint different color as (i-1)th;
            dp[i] = (k-1)* dp[i-1];
            // pointed as different color
            dp[i] += (k-1) * dp[i-2];
        }
        return dp[n-1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
