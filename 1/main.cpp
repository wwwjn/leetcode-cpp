#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> record;
        for(int i = 0 ; i < nums.size(); i++){
            if(record.find(nums[i]) == record.end())
                record.insert(make_pair(target-nums[i], i));
            else{
                res.push_back(i);
                res.push_back(record[nums[i]]);
            }
        }

        return res;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
