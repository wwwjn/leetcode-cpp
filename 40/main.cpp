#include <iostream>


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> s;
        findCombination(candidates, 0, target, s);
        return res;
    }
private:
    vector<vector<int>> res;
    void findCombination(vector<int>& candidates, int index, int target, vector<int> s){
        // [0.. index) has been considered
        // s: selected item
        if(target == 0){
            res.push_back(s);
            return;
        }
        if(target < 0)
            return;
        for(int i = index; i< candidates.size(); i++){
            if(candidates[i] > target)
                break;
            if(i> index && candidates[i] == candidates[i-1])
                continue;
            int new_target = target - candidates[i]; // >=0
            s.push_back(candidates[i]);
            findCombination(candidates, i+1, new_target, s);
            s.pop_back();
        }
        return;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
