#include <iostream>

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> record;
        findCombine(n, 1, k, record);
        return res;
    }
private:
    vector<vector<int>> res;
    // 因为k不固定，不能使用多重循环，只能使用回溯。
    void findCombine(int n, int start, int k, vector<int>& record){
        // [start, n] 选k个数
        if(record.size() == k){
            res.push_back(record);
            return;
        }
        // 还有 k-record.size() 个元素待找，[i...end]中必须有至少k-record.size()个元素
        // end = n- ( k - record.size()) + 1;
        for(int i = start; i <= (n-k + record.size()) +1 ; i++){ // 此处有剪枝
            record.push_back(i);
            findCombine(n, i+1, k, record);
            record.pop_back(); // 回溯，拿出该元素
        }
        return;
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
