#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        }
        int size = nums.size();
        nums.push_back(nums[size-1] + 1);
        int i = 0;  //[0...i)
        int j = 0;  // [j...k] is the same number
        for(int k = 0; k < size; k++){
            if(nums[k+1] != nums[j]){
                if( k > j ){
                    swap(nums[i], nums[j]);
                    swap(nums[i+1], nums[j+1]);
                    j = k+1;
                    i += 2;
                }
                else{
                    swap(nums[i], nums[j]);
                    j = k+1;
                    i++;
                }
            }
        }
        return i;
    }
};



int main() {
    int arr[] = { 0,0,1,1,1,1,2,3,3,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int res = Solution().removeDuplicates(nums);
    cout << res << endl;

    for(int k = 0; k < res; k++){
        cout << nums[k];
    }
    cout << endl;
    return 0;
}
