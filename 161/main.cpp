#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n == m){ // change
            int index = 0;
            int count = 0; // number of different characters
            while(index < n){
                if(s[index] != t[index])
                    count ++;
                index++;
            }
            if(count == 1)
                return true;
            else return false;
        }else if(n == m + 1){ // insert
            int i = 0, j = 0;
            while(i < m && j < n){
                if(s[i] == t[j]){
                    i++;
                    j++;
                }else{   // encouter a different char in t
                    j++;
                }
            }
            if(i != m ) return false;
            else return true;
        }else if(n == m-1){ // delete a char
            int i = 0, j = 0;
            while(i < m && j < n){
                if(s[i] == t[j]){
                    i++;
                    j++;
                }else{   // encouter a different char in t
                    i++;
                }
            }
            if(j != n) return false;
            else return true;
        }else{
            return false;
        }
    }
};