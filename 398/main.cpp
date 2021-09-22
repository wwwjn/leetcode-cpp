#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class Solution {
private:
    unordered_map<int, vector<int>> record;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) == record.end()){
                vector<int> tmp;
                tmp.push_back(i);
                record.insert({nums[i], tmp});
            }else{
                record[nums[i]].push_back(i);
            }
        }
    }

    int pick(int target) {
        vector<int> idx = record[target];
        int n = idx.size();
        int r = random() % n;
        return idx[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */