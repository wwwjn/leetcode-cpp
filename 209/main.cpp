#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0; //[i...j]
        int j = 0;
        int min_len = nums.size() + 1;
        int sum = nums[i];
        while(i < nums.size()){
            if(sum < target){
                if(j < nums.size() -1){
                    j++;
                    sum += nums[j];
                }
                else{
                    break;
                }
            }else{   // >=
                if(j-i+1 < min_len){
                    min_len = j-i+1;
                }
                sum -= nums[i];
                i++;
            }
        }
        if(min_len == nums.size() + 1){
            return 0;
        }
        return min_len;
    }
};

int main() {
    int arr[] = {2,3,1,2,4,3};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    cout << Solution().minSubArrayLen(7,nums);
    return 0;
}
