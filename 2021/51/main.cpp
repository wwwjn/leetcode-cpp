#include <iostream>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n-1, false);
        diag2 = vector<bool>(2*n-1, false);
        vector<int> row;
        putQueen(n, 0, row);
        return res;

    }

private:
    vector<bool> col; // 第i列是否已经有元素，避免冲突
    vector<bool> diag1, diag2;
    vector<vector<string>> res;

    void putQueen(int n, int index, vector<int>& row){
        // 尝试在第index行摆放
        if(index == n){
            res.push_back(genereateBoard(n, row));
            return;
        }
        for(int i = 0; i< n; i++){
            // 尝试在第i列摆放
            if(!col[i] && !diag1[index+i] && !diag2[index-i + n-1]){
                row.push_back(i);
                col[i] = true;
                diag1[index+i] = true;
                diag2[index-i+n-1] = true;
                putQueen(n, index+1, row);
                row.pop_back();
                col[i] = false;
                diag1[index+i] = false;
                diag2[index-i+n-1] = false;
            }
        }

    }
    vector<string> genereateBoard(int n, vector<int>& row){
        vector<string> board(n, string(n, '.'));
        for(int i=0; i< n; i++){
            board[i][row[i]] = 'Q';
        }
        return board;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
