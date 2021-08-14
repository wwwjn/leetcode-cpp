#include <iostream>

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // memo[i][j] : 存储子串的个数。从strs中选出最多的子串，可以正好填满容量为（i，j）的背包
        // 用strs[0] 填充
        if(strs.size() == 0){
            return 0;
        }
        vector<int> count = count01(strs[0]);
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(count[0] <= i && count[1] <= j){
                    memo[0][i][j] = 1;  // 能被strs[0] 填充
                }
            }
        }
        for(int k = 1; k < strs.size(); k++){
            vector<int> count = count01(strs[k]);
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n ; j++){
                    if(i>= count[0] && j >= count[1])
                        memo[k%2][i][j] = max(memo[(k-1)%2][i][j], memo[(k-1)%2][i-count[0]][j-count[1]] + 1);
                    else
                        memo[k%2][i][j] = memo[(k-1)%2][i][j];
                }
            }
        }
        return memo[(strs.size()-1)%2][m][n];
    }
    vector<int> count01(string str){
        vector<int> nums = vector<int>(2, 0);
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0')
                nums[0]++;
            else if(str[i] == '1'){
                nums[1]++;
            }
        }
        return nums;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
