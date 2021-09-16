#include <iostream>

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int prev = 0;
        int index = 0;
        while(index < s.size()){
            if(s[index] == ' '){
                reverse(s, prev, index-1);
                prev = index + 1;
            }
            index ++;
            if(index == s.size()){
                reverse(s, prev, index-1);
            }
        }
        // swap the whole string
        reverse(s, 0, s.size() - 1);
    }

    void reverse(vector<char> &s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start ++;
            end--;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
