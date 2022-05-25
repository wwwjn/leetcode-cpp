#include <iostream>
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // dp[i][j]: s的前i个字符能否和p的前j个字符匹配
        // initialize
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }

        // if(p[0] == '?' || p[0] == '*' || p[0] == s[0])
        //     dp[0][0] = true;
        // if(p[0] == '*'){
        //     for(int i = 1; i< m; i++){
        //         dp[i][0] = true;
        //     }
        // }
        // for(int j = 1; j < n; j++){
        //     if(p[j] == '*'){
        //         dp[0][j] = true;
        //     }
        // }
        // //
        for(int i = 1; i<= m; i++){
            for(int j =1; j<=n; j++){
                if(p[j-1] == '*'){
                    // if the previous can match 0...j-1
                    // bool flag = false;
                    // for(int k = 0; k < i; k++){
                    //     if(dp[k][j-1]) flag = true;
                    //     break;
                    // }
                    // if(flag || dp[i-1][j])
                    //     dp[i][j] = true;
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
