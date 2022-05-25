#include <iostream>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < board.size(); i++){
            visited.push_back(vector<bool>(board[i].size(),false));
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size();j++){
                if(word[0] == board[i][j] && findExist(board, word, 1, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    vector<vector<bool>> visited;
    int m, n;
    bool findExist(vector<vector<char>>& board, string& word, int index, int x, int y){
        //[0, index) has been considered
        // start from (x,y) to find the word[index...]
        if(index == word.size())
            // true;
            return true;
        if(index > word.size()){
            return false;
        }
        // up
        visited[x][y] = true;
        if(inArea(x,y+1) && !visited[x][y+1] && word[index] == board[x][y+1]){
            if(findExist(board, word, index+1, x, y+1))
                return true;
            // 如果寻找失败的话，不返回，继续尝试下一个if
        }// right
        if(inArea(x+1,y) && !visited[x+1][y] && word[index] == board[x+1][y]){
            if(findExist(board, word, index+1, x+1, y))
                return true;
        }// down
        if(inArea(x,y-1) && !visited[x][y-1] && word[index] == board[x][y-1]){
            if(findExist(board, word, index+1, x, y-1))
                return true;
        }// left
        if(inArea(x-1,y) && !visited[x-1][y] && word[index] == board[x-1][y]){
            if(findExist(board, word, index+1, x-1, y))
                return true;
        }
        // 上下左右都没找到，回退
        visited[x][y] = false;
        return false;
    }
    bool inArea(int x, int y){
        return x >=0 && x< m && y>=0 && y<n;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
