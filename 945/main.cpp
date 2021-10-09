#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int low = -1;
        long sum = 0;
        long originSum = 0;
        for(int a: nums){
            low = max(low+1, a);
            sum += low;
            originSum += a;
        }
        return (int) (sum - originSum);
    }
};