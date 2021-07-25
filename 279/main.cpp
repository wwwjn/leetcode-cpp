#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if(num == 0) return step;
            for(int i = 1; num - i*i > 0; i++){
                if( !visited[num-i*i]) {
                    q.push(make_pair(num - i * i, step + 1));
                    visited[num-i*i] = true;
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
