#include <iostream>

class Solution {
public:
    string countAndSay(int n) {
        string r = "1";
        for(int i = 1; i<n; i++){
            r = Say(r);
            cout << r << " ";
        }
        return r;
    }
    string Say(string s){
        string res = "";
        int i = 0;
        int count = 1;
        while(i < s.size()){
            while(i+1 < s.size() && s[i+1] == s[i]){
                count ++;
                i++;  // [0..i]
            }
            res += to_string(count);
            res += to_string(s[i] - '0');
            count = 1;
            i++;
        }
        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
