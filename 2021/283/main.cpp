#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != 0){
                i++;
            }
            else{
                for(int j = i; j < nums.size(); j++){
                    if (nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                i++;
            }
        }
    }
    void moveZeroes2(vector<int>& nums){
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};


int main() {
   int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    Solution().moveZeroes2(vec);

    for(int i =0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
