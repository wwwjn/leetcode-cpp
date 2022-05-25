#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


// dfs: time limit exceed
class Solution {
private:
    int m, n;
    int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    bool inArea(int x, int y){
        return x< m && x >=0 && y<n && y >=0;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(rooms[i][j] == 0){
                    // dfs neighboors
                    dfs(rooms, i, j);
                }
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int x, int y){
        for(int k = 0; k < 4; k++){
            int newx = x + d[k][0];
            int newy = y + d[k][1];
            if(inArea(newx, newy)&&rooms[newx][newy]!=-1 && rooms[newx][newy]!= 0){
                // cut branches
                if(rooms[newx][newy] < rooms[x][y] + 1)
                    continue;
                // update
                rooms[newx][newy] = min(rooms[newx][newy], rooms[x][y] + 1);
                dfs(rooms, newx, newy);
            }
        }
    }
};