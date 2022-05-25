#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    int m;
    int n;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool inArea(int x, int y){
        return x>=0 && x< m && y>=0&& y<n;
    }
    vector<vector<int>> dp;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxLen = 1;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j< n; j++){
                maxLen = max(dfs(i, j, matrix), maxLen);
            }
        }
        return maxLen;

    }
    int dfs(int x, int y, vector<vector<int>>& matrix){
        // return: the maxLength of increasing path
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y]  =1;
        for(int i= 0; i< 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && matrix[newx][newy] > matrix[x][y]){
                dp[x][y] = max(dp[x][y], 1 + dfs(newx, newy, matrix));
            }
        }
        return dp[x][y];
    }
};