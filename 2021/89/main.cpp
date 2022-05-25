#include <iostream>

class Solution{
private:
    int n;
    vector<bool> hash;
    vector<int> res;

public:
    vector<int> grayCode(int n) {
        this->n = n;
        hash.resize(1<<n, 0);
        dfs(0, 1);
        return res;
    }
    bool dfs(int i, int size){
        // size: 是第k个元素，当size=pow(2, n)时停止
        // i: 数字i
        // return: 这条路是否能行。下一层向上一层return
        if(hash[i] == true){
            return false;  // 数字i已经被选过了
        }
        hash[i] = true;  //访问
        res.push_back(i);
        if(size == 1<<n) return true;  // 搜索到底
        for(int k = 0; k < n; k++){ // 从i变化第k位 0->1, 可能有重复的数字，用
            if(dfs(i^(1<<k), size+1)){  // 如果有一个组合能行
                return true;
            }
        }
        // k从0...n-1没有找到可行的解，回溯
        hash[i] = false;
        res.pop_back();
        return false;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
