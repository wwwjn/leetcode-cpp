#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // memo[i][j]: the paths number from (i,j) to the end
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> memo = vector<vector<long>>(m, vector<long>(n, 0));
        // special cases.
        if(m == 1 || n == 1){
            for(int i = 0; i< m; i++){
                for(int j = 0; j< n; j++){
                    if(obstacleGrid[i][j] == 1)
                        return 0;
                }
            }
            return 1;
        }
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        memo[m-1][n-1] = 1;
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>= 0; j--){
                long right=0;
                long bottom=0;
                if(i == m-1 && j == n-1){
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    cout << "0 ";
                    continue;
                }
                // from right
                if(inArea(i+1, j, m, n) && obstacleGrid[i+1][j] == 0)
                    right = memo[i+1][j];
                if(inArea(i, j+1, m ,n) && obstacleGrid[i][j+1] == 0)
                    bottom = memo[i][j+1];
                memo[i][j] = bottom + right;
                cout << memo[i][j] << " ";
            }
            cout << endl;
        }
        return memo[0][0];
    }
private:
    bool inArea(int x, int y, int m, int n){
        return x>=0 && x< m && y>=0 && y<n;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
