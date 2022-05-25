#include <iostream>
#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "queue"
#include "stack"
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        queue<char> q;
        stack<char> st;
        char c = st.top();
        st.pop();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                q.push(s[i]);
            }else{
                if(q.size() == 0)
                    return false;
                else{
                    char t = q.front();
                    q.pop();

                }
            }
        }
    }
};

int main() {


}
