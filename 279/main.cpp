#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares2(int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if(num == 0) return step;

            for(int i = 1; num - i*i >= 0; i++){
                if( !visited[num-i*i]) {
                    q.push(make_pair(num - i * i, step + 1));
                    visited[num-i*i] = true;
                }
            }
        }
        return -1;
    }
    int numSquares(int n){
        // memo保存了i的最少的完全平方数分割
        vector<int> memo = vector<int>(n+1, 10001);
        memo[0] = 0;
        for(int i = 1; i*i <= n; i++){
            memo[i*i] = 1;
        }
        for(int i = 2; i <= n ; i++){
            for(int j = 1; j*j < i; j++){
                memo[i] = min(memo[i], memo[i-j*j] + 1);
            }
        }
        return memo[n];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
