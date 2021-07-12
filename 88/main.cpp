#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;  //considering i;
        int j = n-1;  //considering j;
        for(int k=m+n-1; k>=0; k--){
            if(i < 0){
                nums1[k] = nums2[j];
                j--;
                continue;
            }
            if(j < 0){
                nums1[k] = nums1[i];
                i--;
                continue;
            }
            if(nums1[i] < nums2[j]){
                nums1[k] = nums2[j];
                j--;
            }else{
                nums1[k] = nums1[i];
                i--;
            }
        }
    }
};

int main() {
    int arr[] = {0};
    vector<int> nums1(arr, arr + sizeof(arr) / sizeof(int));
    int arr2[] = {1};
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    Solution().merge(nums1, 0, nums2, 1);

    for(int k = 0; k < nums1.size(); k++){
        cout << nums1[k];
    }
    return 0;
}
