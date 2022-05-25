#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Solution {
public:
    int trap(vector<int>& height) {
        // i=2; h[i] =0;
        // left highest: 1
        // right higest: 3
        // water[2] = (min(left highest, right highest) - h[i]) * 1;
        vector<int> maxLeft(height.size(), 0);
        // vector<int> maxRight(height.size(), 0);
        int mx = 0;
        for(int i = 0; i < height.size(); i++){
            // [0..i-1]
            maxLeft[i] = mx;
            //cout << mx << " ";
            mx = max(height[i], mx);
        }
        // cout << endl;

        // from right side
        mx = 0;
        int res = 0;
        vector<int> maxRight(height.size(), 0);
        for(int i = height.size()-1; i>=0; i--){
            maxRight[i] = mx;
            mx = max(height[i], mx);
            if(maxRight[i] >= height[i] && maxLeft[i] >= height[i])
                res += (min(maxRight[i], maxLeft[i]) - height[i]);
        }

        return res;

    }
};