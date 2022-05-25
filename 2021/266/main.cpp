#include <iostream>

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int arr[26] = {0};
        for(int i = 0; i< s.size(); i++){
            arr[s[i]-'a'] ++;
        }
        bool singleFlag = false;
        for(int i = 0; i< 26; i++){
            if(arr[i]%2 == 0)
                continue;
            if(!singleFlag && arr[i] % 2 != 0)
                singleFlag = true;
            else if(singleFlag && arr[i] % 2 != 0)
                return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
