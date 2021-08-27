//
// Created by Jiani Wang on 2021/8/26.
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // find the row range
        int row_start = 0;
        int row_end = 0;
        int col_start = 0;
        int col_end = 0;
        for(int i = 0; i < m; i++){
            if(matrix[i][n-1] < target){
                row_start ++;
                row_end ++;
            }
            else if(matrix[i][0] > target){
                break;
            }else{
                row_end ++;
            }
        }

        // find the range of column
        for(int j = 0; j < n; j++){
            if(matrix[m-1][j] < target){
                col_start ++;
                col_end++;
            }else if(matrix[0][j] > target){
                break;
            }else{
                col_end++;
            }
        }
        // cout << row_start << " " << row_end << endl;
        // cout << col_start << " " << col_end << endl;
        for(int i = row_start; i< row_end; i++){
            for(int j = col_start; j< col_end; j++){
                if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }

};