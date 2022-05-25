#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res = "";
        int n = s.size();
        unordered_set<int> bold;
        for (string word : dict) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (s[i] == word[0] && s.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold.count(i) && !bold.count(i - 1)) res += "<b>";
            res += s[i];
            if (bold.count(i) && !bold.count(i + 1)) res += "</b>";
        }
        return res;
    }
};