#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_area = area(height, l, r);
        while(l < r){
            if(area(height, l, r) > max_area){
                max_area = area(height, l, r);
            }
            if(height[l] <= height[r]){
                l = findNextLarge(height, l);
            }
            else{
                r = findPrevLarge(height, r);
            }
        }
        return max_area;
    }
    int area(vector<int> &height, int left, int right){
        if (right > left)
            return min(height[left], height[right]) * (right - left);
        else
            return 0;
    }
    int findNextLarge(vector<int> &height, int left){
        int i = left + 1;
        while(i < height.size()){
            if(height[left] >= height[i]){
                i++;
            }else{
                break;
            }
        }
        return i;
    }
    int findPrevLarge(vector<int> &height, int right){
        int i = right - 1;
        while(i > 0){
            if(height[right] >= height[i]){
                i--;
            }else{
                break;
            }
        }
        return i;
    }

};

int main() {
    int arr[] = {4,3,2,1,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    cout << Solution().maxArea(nums) ;
    return 0;
}
