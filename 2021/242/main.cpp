#include <iostream>

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26, 0);
        for(int i = 0; i < s.size(); i++){
            arr[s[i]-'a'] ++;
        }
        for(int i = 0; i < t.size(); i++){
            arr[t[i]-'a'] --;
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
