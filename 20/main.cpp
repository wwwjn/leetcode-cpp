#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(s1.empty()) return false;
                char pair = s1.top();
                s1.pop();
                if(pair == '(') continue;
                else return false;
            }
            else if(s[i] == '}'){
                if(s1.empty()) return false;
                char pair = s1.top();
                s1.pop();
                if(pair == '{') continue;
                else return false;
            }
            else if(s[i] == ']'){
                if(s1.empty()) return false;
                char pair = s1.top();
                s1.pop();
                if(pair == '[') continue;
                else return false;
            }
            else s1.push(s[i]);
        }
        if(!s1.empty()) return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
