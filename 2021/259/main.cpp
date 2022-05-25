#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if(nums[j] + nums[k] < t){
                    res += (k-j); // [i,j,k]
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};