#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        dfs(candidates, target, 0, r, res);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int i, vector<int>& r, vector<vector<int>>& res){
        // consider the ith element in the candidates
        if(target == 0){
            res.push_back(r);
            return;
        }
        if(i >= candidates.size()) return;
        // cout << candidates[i] << " " << target << " " << i << endl;


        if(candidates[i] > target) return;

        r.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i, r, res);
        r.pop_back();
        dfs(candidates, target, i+1, r, res);
    }
};