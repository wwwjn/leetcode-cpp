#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0; // [0...i] contains no duplicate item
        for(int j=1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                //swap
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
        return i + 1;
    }
};

int main() {
    int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int res = Solution().removeDuplicates(nums);
    cout << res << endl;

    for(int k = 0; k < res; k++){
        cout << nums[k];
    }
    cout << endl;
    return 0;
}
