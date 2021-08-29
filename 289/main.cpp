#include <iostream>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 记录每个cell周围有几个活细胞
        m = board.size();
        n = board[0].size();
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] %10 == 0){
                    continue;
                }else{
                    // 用十位来表示附近有几个live cell
                    for(int k = 0; k< 8; k++){
                        int newx = i + d[k][0];
                        int newy = j + d[k][1];
                        if(inArea(newx, newy))
                            board[newx][newy] += 10;
                    }
                }
            }
        }
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(board[i][j] <= 20 || board[i][j] >= 40)
                    board[i][j] = 0; // dead
                else if(board[i][j] == 30 || board[i][j]== 21 || board[i][j]== 31)
                    board[i][j] = 1; // live
            }
        }

    }
private:
    int n, m;
    int d[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    bool inArea(int i, int j){
        return i>=0 && i <m && j>=0 && j<n;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
