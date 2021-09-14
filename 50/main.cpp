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

class Solution {
public:
    double fastPower(double x, long long n){
        if(n == 0){
            return 1.0;
        }
        double half = fastPower(x, n/2);
        if(n % 2 == 0){
            return half * half;
        }else{
            return half * half * x;
        }
    }
    double myPow(double x, int n){
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        return fastPower(x, N);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
