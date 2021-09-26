#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int res = 0;
        int i = 0;
        while(count < k){
            res++;
            if(i < arr.size()){
                if(res != arr[i]) count++;
                else i++;
            }else{
                count++;
            }

        }
        return res;
    }
};