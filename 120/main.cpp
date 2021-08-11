#include <iostream>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo; // 到达该点的最小代价
        for(int i = 0; i< triangle.size(); i++){
            memo.emplace_back(triangle[i]);
        }
        if(triangle.size() == 1){
            return memo[0][0];
        }
        int n = triangle.size();
        for(int i = triangle.size()-2; i>=0 ; i--){
            vector<int> temp;
            for(int j = 0; j< triangle[i].size(); j++){
                int num = min(memo[i+1][j], memo[i+1][j+1]) + triangle[i][j];
                memo[i][j] = num;
            }
        }

        return memo[0][0];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
