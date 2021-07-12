#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // [0...i) does not contains 'val'
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] != val){
                if(j != i) {
                    // swap
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                i++;
            }
        }
        return i;
    }
};

int main() {
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int res = Solution().removeElement(nums, val);
    cout << res << endl;

    for(int k = 0; k < res; k++){
        cout << nums[k] << ":" <<(bool)(nums[k] == val) << endl;
    }

    return 0;
}
