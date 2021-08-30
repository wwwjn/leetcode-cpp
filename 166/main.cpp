#include <iostream>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        long long num=static_cast<long long>(numerator);
        long long denom=static_cast<long long>(denominator);
        string res;
        if((num>0)^(denom>0)) res.push_back('-');
        num=llabs(num),denom=llabs(denom);
        res += to_string(num/denom);
        if(num % denom == 0) return res;
        res.push_back('.');

        num = num % denom;

        unordered_map<int,int> numToIndex; // (residential, index in string res);

        int index = res.size();
        while(num && !numToIndex.count(num)){
            numToIndex[num]=index;
            num*=10;
            res += to_string(num/denom);
            num %= denom;
            index++;
        }
        if(numToIndex.count(num)){
            res.insert(numToIndex[num],"(");
            res.push_back(')');
        }

        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
