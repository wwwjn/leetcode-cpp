#include <iostream>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 0){
            return;
        }
        bool less = true; // is nums[i] should less than
        for(int i = 0; i< nums.size()-1; i++){
            if(less){
                if(nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }else{
                if(nums[i] < nums[i+1]){
                    swap(nums[i], nums[i+1]);
                }
            }
            less = !less;
        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
