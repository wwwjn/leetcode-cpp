#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    bool inArea(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y< n;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // (x,y) x+y == same value
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        for(int i = 0; i< m+n-1; i++){
            cout<< i<< endl;
            if(i % 2 != 0){
                for(int j = 0; j<=i; j++){
                    if(inArea(j, i-j,m,n)) res.push_back(mat[j][i-j]);
                }
            }else{
                for(int j = i; j>=0; j--){
                    if(inArea(j, i-j,m,n)) res.push_back(mat[j][i-j]);
                }
            }
        }
        return res;
    }
};