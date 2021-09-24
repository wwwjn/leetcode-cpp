#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // traverse the first line
        for(int i = 0; i < m; i++){

            int x=i, y=0;
            int target = matrix[x][y];
            while(inArea(x+1, y+1, m, n)){
                x++;
                y++;
                if(matrix[x][y] != target){
                    return false;
                }
            }
        }
        // traverse the first column
        for(int i = 1; i < n; i++){
            int x = 0, y =i;
            int target = matrix[x][y];
            while(inArea(x+1, y+1, m, n)){
                x++;
                y++;
                if(matrix[x][y] != target) return false;
            }
        }
        return true;
    }
    bool inArea(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
};