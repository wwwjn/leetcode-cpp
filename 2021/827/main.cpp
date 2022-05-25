#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    int m, n; // size of grid
    int d[4][2] = {{0,1}, {0, -1},{1, 0}, {-1, 0}};
    bool inArea(int x, int y){
        return x>=0 && x < m && y>=0 && y<n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // record the island index;
        vector<vector<int>> idx = vector<vector<int>>(m, vector<int>(n, -1));
        int curIdx = 0; // index start from 0
        map<int, int> record; // Island index -> Island size;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // recursive dfs
                if(grid[i][j] == 0 || idx[i][j] != -1)
                    continue;
                // find a new Island
                int size = 1;
                dfs(grid, idx, i, j, curIdx, size);
                record.insert({curIdx, size});
                // cout << curIdx << " " << size << endl;
                curIdx++;
            }
        }
        // traverse every 0 in grid
        int res = 0;
        for(auto s = record.begin(); s!= record.end(); ++s){
            res = max(res, s->second);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    continue;
                // change grid[i][j] from 0 to 1
                set<int> nei;
                for(int k = 0 ; k < 4; k++){
                    int newx = i + d[k][0];
                    int newy = j + d[k][1];
                    if(inArea(newx, newy) && grid[newx][newy] == 1)
                        nei.insert(idx[newx][newy]);
                }
                int tmp = 1;
                for(auto s = nei.begin(); s!= nei.end(); ++s){
                    tmp += record[*s];
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& idx, int x, int y, int curIdx, int& size){
        // size: current size of Island of 'idx'
        idx[x][y] = curIdx;
        for(int i = 0 ; i<4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && idx[newx][newy] == -1 && grid[newx][newy] == 1){
                size++;
                dfs(grid, idx, newx, newy, curIdx, size);
            }
        }
    }

};