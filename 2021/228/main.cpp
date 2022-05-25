#include <iostream>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        int j = 1;
        vector<string> res;
        while(j <= nums.size()){
            // [i...j)
            int record = nums[i];
            while(j < nums.size() && nums[j-1] == nums[j]-1){
                j++;
                record++;
            }
            if(i == (j-1)){
                res.push_back(to_string(nums[i]));
                i++;
                j++;
            }else{
                res.push_back(change(nums[i], nums[j-1]));
                i = j;
                j++;
            }
        }
        return res;
    }
    string change(int start, int end){
        return to_string(start) + "->" + to_string(end);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
