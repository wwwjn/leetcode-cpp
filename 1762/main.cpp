#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int index = heights.size() -1;
        vector<int> res;
        res.push_back(index);
        int highest = heights[index];
        index--;
        while(index >= 0){
            if(heights[index] <= highest){
                index--;
            }else{
                highest = heights[index];
                res.push_back(index);
                index--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};