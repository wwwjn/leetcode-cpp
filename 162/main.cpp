#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeak(nums, 0, nums.size()-1);
    }
private:

    int findPeak(vector<int>& nums, int i, int j){
        if(i == j){
            return i; // index of the peak element
        }
        if(j == i+1){
            return nums[i] > nums[j] ? i:j;
        }
        // peak is in [i...j]
        int mid = (i+j)/2;
        if(nums[mid+1] > nums[mid]){
            return findPeak(nums, mid+1, j);
        }else{
            return findPeak(nums, i, mid);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
