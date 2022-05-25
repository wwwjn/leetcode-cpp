#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[] = {0,0,0};
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        int index = 0;
        for(int j=0; j < 3; j++){
            for(int i=0; i < count[j]; i++){
                nums[index+i] = j;
            }
            index += count[j];
        }
    }
    void sortColors2(vector<int>& nums) {
        int zero = -1; // [0...zero] == 0;
        int two = nums.size(); // [two...nums.size()-1] == 2
        for(int i = 0; i < two; ){
            if(nums[i] == 0) {
                swap(nums[i], nums[zero+1]);
                zero++;
                i++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[two-1]);
                two--;
                // do not change i when
            }else{
                i++;
            }
        }
    }
};


int main() {
    int arr[] = {1,2,0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution().sortColors2(nums);

    for(int k = 0; k < nums.size(); k++){
        cout << nums[k];
    }
    return 0;
}
