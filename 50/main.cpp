#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N>=0 ? quickMul(x, N): 1.0/quickMul(x, -N);
    }
    double quickMul(double x, long long n){
        if(n == 0){
            return 1.0;
        }
        double y = quickMul(x, n/2);
        double res = y*y;
        if(n % 2 != 0)
            res *= x;
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
