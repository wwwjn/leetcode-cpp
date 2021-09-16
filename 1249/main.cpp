#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pos;
        vector<int> del_pos;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '('){
                pos.push(i);
            }else if(s[i] == ')'){
                if(pos.empty()) del_pos.push_back(i);
                else pos.pop();
            }
        }
        while(!pos.empty()){
            int k = pos.top();
            del_pos.push_back(k);
            pos.pop();
        }
        sort(del_pos.begin(), del_pos.end());
        string res = "";
        int prev = 0;
        for(int i = 0; i < del_pos.size(); i++){
            // add string from s[prev, del_pos[i]-1]
            // cout << del_pos[i] << " : " << s.substr(prev, del_pos[i]-prev) << endl;
            res += s.substr(prev, del_pos[i]-prev);
            prev = del_pos[i] +1;
        }
        res += s.substr(prev, s.size()-prev);
        return res;
    }
};