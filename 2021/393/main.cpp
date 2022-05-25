#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int left = 0;
        for(int i = 0; i< data.size(); i++){
            if(left == 0){ // check the first byte
                if((data[i] >> 3) == 0b11110) left = 3;
                else if((data[i] >> 4) == 0b1110) left = 2;
                else if((data[i] >> 5) == 0b110) left = 1;
                else if(data[i] < 0b10000000) left = 0;
                else return false;
            }else{
                if((data[i] >> 6) == 0b10)
                    left--;
                else return false;
            }
        }
        return left == 0;
    }
};