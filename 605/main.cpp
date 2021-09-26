#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            bool flag = true;
            if(flowerbed[i] == 1) flag = false;
            if(i > 0 && flowerbed[i-1] == 1)
                flag = false;
            if(i < flowerbed.size()-1 && flowerbed[i+1] == 1)
                flag = false;
            if(flag){
                res++;
                flowerbed[i] = 1;
            }
        }
        if(res >= n)
            return true;
        else return false;
    }
};