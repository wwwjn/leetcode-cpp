#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l= 0, r= 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                l++;
            }else if(s[i] == ')'){
                if(l>0) l--;
                else r++;
            }
        }
        vector<string> res;
        dfs(s, 0, l,r, res);
        return res;
    }
private:
    bool isValid(string s){
        int count = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '(')
                count++;
            else if(s[i] == ')'){
                count--;
                if (count < 0) return false;
            }
        }
        return count ==0;
    }

    void dfs(const string& s, int start, int l, int r,vector<string>& res){
        if(l == 0 && r==0){
            if(isValid(s)) res.push_back(s);
            return;
        }
        for(int i = start; i< s.size(); i++){
            if(i != start && s[i] == s[i-1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string curr = s;
                curr.erase(i, 1);
                if (r > 0 && s[i] == ')')
                    dfs(curr, i, l, r - 1, res);
                else if (l > 0 && s[i] == '(')
                    dfs(curr, i, l - 1, r, res);
              }
        }
    }
};