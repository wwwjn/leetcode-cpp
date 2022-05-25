#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l <= r){
            if(numbers[l] + numbers[r] < target){
                l++;
            }else if(numbers[l] + numbers[r] > target){
                r++;
            }else{
                break;
            }
        }
        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
