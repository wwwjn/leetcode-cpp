#include <iostream>

class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo = vector<int>(n+1, 0);
        memo[1] = 1;
        memo[2] = 1;
        for(int i = 3; i <= n; i++){
            // 求i 的integerBreak
            int res=0;
            for(int j = 1; j < i; j++){
                res = max3(res, memo[i-j]*j, (i-j)*j);
            }
            memo[i] = res;
        }
        return memo[n];
    }
    int max3(int a, int b, int c){
        return max(a, max(b,c));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
