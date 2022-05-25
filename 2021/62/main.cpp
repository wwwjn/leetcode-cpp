#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // memo[i][j]: the paths number from (i,j) to the end
        vector<vector<int>> memo = vector<vector<int>>(m, vector<int>(n, -1));
        if(m == 1 || n == 1)
            return 1;
        memo[m-1][n-1] = 1;
        memo[m-2][n-1] = 1; // from left
        memo[m-1][n-2] = 1; // from top
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>= 0; j--){
                int right, bottom;
                if(memo[i][j] != -1){
                    continue;
                }
                if(inArea(i+1, j, m, n))
                    right = memo[i+1][j];
                else
                    right = 0;
                if(inArea(i, j+1, m ,n))
                    bottom = memo[i][j+1];
                else
                    bottom = 0;
                memo[i][j] = bottom + right;
            }
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
