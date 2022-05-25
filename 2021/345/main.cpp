#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(!isVowel(s[i]) && i<j){
            i++;
        }
        while(!isVowel(s[j]) && i<j){
            j--;
        }
        while(i < j){
            swap(s[i++], s[j--]);
            while(!isVowel(s[i])){
                i++;
            }
            while(!isVowel(s[j])){
                j--;
            }
            cout << i << j;
        }
        return s;
    };
    bool isVowel(char c){
        char lowerc = tolower(c);
        return lowerc == 'a' || lowerc == 'e' || lowerc == 'i' || lowerc == 'o' || lowerc == 'u';
    }
};

int main() {
    string s = "leetcode";
    cout <<  Solution().reverseVowels(s) << endl;
    return 0;
}
