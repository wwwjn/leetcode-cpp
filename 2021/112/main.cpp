#include <iostream>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for(int i = 0; i< prices.size(); i++){
            int num1 = prices[i];
            if(num1 < minPrice){
                minPrice = num1;
            }else if(num1 - minPrice > profit){
                profit = num1 - minPrice;
            }
        }
        return profit;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
