//
// Created by Jiani Wang on 2021/8/22.
//


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0'){
            return 0;
        }
        vector<int> dp(n+1, 0);
        // dp[i]: s的前n个字符有多少种解释方式
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            if(s[i-1]!= '0')
                dp[i] += dp[i-1];
            if(atoi(s.substr(i-2, 2).c_str()) <= 26 && s[i-2] != '0'){
                dp[i] += dp[i-2];
            }

        }
        return dp[n];
    }
};