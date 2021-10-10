#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        unordered_set<string> record(words.begin(), words.end());
        vector<bool> bold(s.size(), false);
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            for(int l = 1; l <= min(n-i, 10); l++){
                // [i...i+l-1]
                string sub = s.substr(i, l);
                if(record.find(sub) != record.end()){
                    std::fill(bold.begin()+i, bold.begin()+i+l, true);
                }
            }
        }
        string res = "";
        for(int i=0; i<bold.size(); i++){
            if(bold[i] == true && (i==0 || bold[i-1] == false))
                res += "<b>";
            res += s[i];
            if(bold[i]== true && (i == bold.size()-1 || bold[i+1] == false)){
                res += "</b>";
            }
        }
        return res;
    }
};