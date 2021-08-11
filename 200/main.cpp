#include <iostream>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false)); // m*n
        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;

    }
private:
    int m;
    int n;
    int num;
    int d[4][2] = {{1,0},{0,1}, {-1,0},{0, -1}};
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1'){
                dfs(grid, newx, newy);
            }
        }
        // 不需要回退，没有回溯的过程，因为不需要找到一个序列
        return;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
