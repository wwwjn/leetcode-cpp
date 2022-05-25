#include <iostream>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> s;
        findSubsets(nums, 0, s);
        return res;
    }
private:
    vector<vector<int>> res;
    void findSubsets(vector<int>& nums, int index, vector<int>& s){
        // [0, index)
        // s: selected set
        if(index == nums.size()){
            res.push_back(s);
            return;
        }
        if(index > nums.size()){
            return;
        }
        // 每一层只需要做两个决策

        // do not select i
        findSubsets(nums, index + 1, s);

        // select item i
        s.push_back(nums[index]);
        findSubsets(nums, index + 1, s);
        s.pop_back();  //回溯

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
