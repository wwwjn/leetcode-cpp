#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class NumMatrix {
private:
    vector<vector<int>> record;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        record = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                record[i+1][j+1] = record[i+1][j] + record[i][j+1] - record[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return record[row2+1][col2+1] - record[row2+1][col1] - record[row1][col2+1] + record[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class NumMatrix {
private:
    vector<vector<int>> record;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        record = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                record[i+1][j+1] = record[i+1][j] + record[i][j+1] - record[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return record[row2+1][col2+1] - record[row2+1][col1] - record[row1][col2+1] + record[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */