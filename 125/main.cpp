#include <iostream>
#include "string"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = next_alpha_numeric(s, 0);
        int j = prev_alpha_numeric(s, s.size() - 1);
        while(i <= j){
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i = next_alpha_numeric(s, i + 1);
            j = prev_alpha_numeric(s, j - 1);
        }
        return true;
    }

private:
    int next_alpha_numeric(const string& s, int index){
        for(int i = index ; i < s.size() ; i ++)
            if(isalnum(s[i]))
                return i;
        return s.size();
    }

    int prev_alpha_numeric(const string& s, int index){
        for(int i = index ; i >= 0 ; i --)
            if(isalnum(s[i]))
                return i;
        return -1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
