#include <iostream>


class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> record;
        bfs(s, 0, record);
        return res;
    }
    void bfs(string& s, int index, vector<string>& record){
        // [0... index) has been devided into palindrome parts
        // record: [0...index) palindrome parts
        if(index > s.size()){
            return;
        }
        if(index == s.size()){
            res.push_back(record);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                // [index, i] is Palindrome
                vector<string> copy;
                // 注意此处要copy，不然会传入错读的record
                copy.insert(copy.end(), record.begin(), record.end());
                copy.push_back(s.substr(index, i-index+1));
                bfs(s, i+1, copy);
            }
            else{
                continue;
            }
        }
    }

    bool isPalindrome(string& s, int start, int end){
        // [start, end]
        if(end < start) return false;
        if(end == start){
            return true;
        }
        int i = start;
        int j = end;
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
