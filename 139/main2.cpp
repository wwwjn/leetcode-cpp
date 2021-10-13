//
// Created by Jiani Wang on 2021/10/10.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //两重循环，第一重循环dp[j] 表示 s[0..j)是否可以用wordDict中的进行表示。第二重循环从0-j，尝试划分。
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            // try to splite [0...i]
            for(int j = 0; j < i; j++){
                // [0...j]
                string sub = s.substr(j, i-j);
                if(dp[j] && dict.find(sub) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};