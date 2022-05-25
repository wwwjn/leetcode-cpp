#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int i = 0;
        int j = 0;  // [i..j)
        int res = 0;
        while(j <= nums.size()){
            while(count > k && i < j){
                if(nums[i] == 0) count--;
                i++;
            }
            // cout << i << ": " << j << endl;
            res = max(res, j-i);

            if(j < nums.size() && nums[j] == 0) count++;
            j++;
        }
        return res;
    }
};