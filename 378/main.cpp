#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int n = matrix.size();
        int r = matrix[n-1][n-1];
        while (l < r) {
            long m = l + (r - l) / 2;
            int count = 0;
            int x= n-1, y =0;
            for(y=0; y < n; y++){
                if(x < 0) break;
                while(x>= 0 && matrix[y][x] > m){
                    x--;
                }
                count += (x+1);
            }
            if(count < k){
                l = m+1;
            }else{
                r = m;
            }
        }
        return l;

    }
};