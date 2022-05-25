class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // dp[i][j]: whether can s[0...i) matches p[0...j]
        dp[0][0] = true;
        for(int i=0; i<=m; i++){
            for(int j = 1; j <=n; j++){
                if(p[j-1] == '*'){
                    // 考虑p中第j-1个字符是什么（*前面的字符是什么）
                    dp[i][j] = dp[i][j] || dp[i][j-2]; // 扔掉p中的“x*”
                    if(matches(s, p, i, j-1)){ // 扔掉s中的一个字符，而p中的
                        dp[i][j] = dp[i-1][j] || dp[i][j];
                    }
                }else{
                    if(matches(s, p, i, j)){
                        dp[i][j] = dp[i][j] || dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
private:
    bool matches(string& s, string& p, int i, int j){
        if(i == 0){  // s is "" empty string
            return false;
        }
        if(s[i-1] == p[j-1] || p[j-1] == '.')
            return true;
        else
            return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
