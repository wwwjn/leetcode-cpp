#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    int m;
    int n;
    bool inArea(int x, int y){
        return x>=0 && x < m && y>=0 && y< n;
    }
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<bool>> visited;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res=0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(grid, i, j, res);
                    break;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int& res){
        visited[x][y] = true;
        for(int i = 0; i< 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(!inArea(newx,newy)) res++;
            else{
                if(grid[newx][newy] == 0) res++;
                else if(!visited[newx][newy] && grid[newx][newy] == 1)
                    dfs(grid, newx, newy, res);
            }
        }
    }
};