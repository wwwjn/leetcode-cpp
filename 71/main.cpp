#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<string> s;
        for(int i = 0; i < path.size(); ){
            while(path[i] == '/'){  // skip the '/'
                i++;
            }
            string temp = "";
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == "..") s.pop();
            else if(temp == ".") continue;
            else s.push(temp);
        }
        while(!s.empty()){
            res += "/";
            res += s.top();
            s.pop();
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
