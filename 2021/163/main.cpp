#include <iostream>

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0){
            if(lower == upper){
                res.push_back(to_string(lower));
            }else if(upper > lower){
                res.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return res;
        }
        int start = lower;
        int end = nums[0]-1;

        for(int i = 0; i < nums.size(); i++){
            if(end < start){
            }else if(end == start){
                res.push_back(to_string(end));
            }else{
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            start = nums[i] + 1;
            if(i+1 < nums.size()) end = nums[i+1] - 1;
            else end = upper;
        }
        start = nums[nums.size()-1]+1;
        end = upper;
        if(end == start){
            res.push_back(to_string(end));
        }else if(end > start){
            res.push_back(to_string(start) + "->" + to_string(end));
        }

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
