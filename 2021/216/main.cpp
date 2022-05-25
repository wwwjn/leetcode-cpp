#include <iostream>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> record;
        if(n > 45){
            return res;
        }
        findCombination(k, n, 1, record);
        return res;
    }
private:
    vector<vector<int>> res;
    void findCombination(int k, int target, int index, vector<int>& record){
        // k: need k numbers (total)
        //
        if(record.size() == k && target == 0){
            res.push_back(record);
            return;
        }
        else if(record.size() != k && target == 0){
            return;
        }else if(record.size() == k && target != 0){
            return;
        }
        if(record.size() > k || target < 0)
            return;
        // [1...index) has been considered
        for(int i = index; i<= 9; i++){
            if(i > target)
                break;
            int new_target = target -i;
            record.push_back(i);
            findCombination(k, new_target, i+1, record);
            record.pop_back();  // 回溯
        }
        return;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
