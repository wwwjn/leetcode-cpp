#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i]=="/"){
                int val1 = s1.top();
                s1.pop();
                int val2 = s1.top();
                s1.pop();
                if(tokens[i] == "+") s1.push(val1 + val2);
                else if(tokens[i] == "-") s1.push(val2 - val1);
                else if(tokens[i] == "*") s1.push(val2 * val1);
                else s1.push(val2 / val1);
            }
            else{
                int num = atoi(tokens[i].c_str()); // string to int
                s1.push(num);
            }
        }
        return s1.top();
    }
};


int main() {
    cout << 3/2 << endl;
    return 0;
}
