#include <iostream>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 顺时针：左上-右下主对角线翻转 + 左右翻转
        // 逆时针：右上-坐下次对角线反转 + 左右反转

        int n = matrix.size();
        if(n == 1){
            return;
        }
        for(int i = 0; i< n; i++){
            for(int j = i+1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 左右
        for(int j = 0; j < n/2; j++){
            for(int i = 0; i<n; i++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
