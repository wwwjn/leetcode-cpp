//
// Created by Jiani Wang on 2021/8/19.
//

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(findWord(board, word, i, j, 0, visited)){
                    return true;
                }
            }
        }
        return false;

    }
private:
    int m;
    int n;
    int d[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
    bool findWord(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited){
        // start from position (i,j);
        // index: To find the word[index...] in the board;
        if(board[i][j] != word[index])
            return false;
        else if(index == word.size()-1){
            return true;
        }
        visited[i][j] = true;
        for(int k = 0; k<4; k++){
            int newx = i + d[k][0];
            int newy = j + d[k][1];
            if(inArea(newx, newy) && !visited[newx][newy]){
                if(findWord(board, word, newx, newy, index+1, visited))
                    return true;
            }
        }
        // not found: traceback
        visited[i][j] = false;
        return false;
    }
    bool inArea(int x, int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
};