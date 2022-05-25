#include <iostream>

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used; // nums[i] 是否已经在排列中出现过了
    void Permutation(vector<int>& nums, int index, vector<int>& p){
        // [0, index) has been considered
        // p: [0, index) 的排列
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false){ // nums[i] 不在p中
                p.push_back(nums[i]);
                used[i] = true;
                Permutation(nums, index+1, p);
                //回溯
                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        if(nums.size() == 0){
            return res;
        }
        vector<int> p;
        Permutation(nums, 0, p);
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
