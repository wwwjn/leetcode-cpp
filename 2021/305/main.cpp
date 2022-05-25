#include <iostream>


// 解法1，在test case125挂了（还未debug）
class Solution {
private:
    int size_m, size_n;
    int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        size_m = m;
        size_n = n;
        vector<int> res;
        int count = 0;
        vector<vector<int>> record = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < positions.size(); i++){
            vector<int> temp = positions[i];
            vector<int> nei;
            if(record[temp[0]][temp[1]] != 0){
                res.push_back(count);
                continue;
            }

            for(int j = 0 ; j < 4; j++){
                int newx = temp[0] + d[j][0];
                int newy = temp[1] + d[j][1];
                if(inArea(newx, newy) && record[newx][newy] != 0){
                    // push island index
                    nei.push_back(record[newx][newy]);
                }
            }
            // deal with neighbor
            if(nei.size() == 0){
                count ++;
                record[temp[0]][temp[1]] = count;
                res.push_back(count);
            }else if(nei.size() == 1){
                record[temp[0]][temp[1]] = nei[0];
                res.push_back(count); // merge the cell into island

            }else{  //nei.size() >= 2 && nei.size() <= 4
                sort(nei.begin(), nei.end());
                for(int j = 1; j < nei.size(); j++){
                    // union land nei[j], nei[j-1]
                    cout << nei[j] << " "<< nei[j-1] << endl;
                    if(nei[j] == nei[j-1])
                        continue; // do not need Union
                    int old = max(nei[j], nei[j-1]);
                    int target = min(nei[j], nei[j-1]);
                    record[temp[0]][temp[1]] = target;
                    Union(record, temp[0], temp[1], old, target);
                    cout << old << " "<< target << endl;
                    count--;
                    cout << "count: " << count << endl;
                }
                res.push_back(count);
            }
        }
        return res;
    }
    bool inArea(int x, int y){
        return x>=0 && x<size_m && y>=0 && y<size_n;
    }
    void Union(vector<vector<int>>& record, int x, int y, int old, int target){
        // union land 'old' and land 'target';
        for(int i = 0; i< 4; i++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && record[newx][newy] == old){
                record[newx][newy] = target;
                Union(record, newx, newy, old, target);
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
