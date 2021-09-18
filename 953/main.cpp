#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    unordered_map<char, int> record;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++){
            record.insert({order[i], i});
        }
        for(int i = 0; i< words.size() - 1; i++){
            if(!isLess(words[i], words[i+1])){
                return false;
            }
        }
        return true;
    }
    bool isLess(string a, string b){  // a<=b
        int i = 0;
        int j = 0;
        while(i< a.size() && j < b.size()){
            if(record[a[i]] < record[b[j]]){
                return true;
            }else if(record[a[i]] > record[b[j]]){
                return false;
            }else{
                i++;
                j++;
            }
        }
        if(i == a.size() && j != b.size()){
            return true;
        }else if(i != a.size() && j == b.size()){
            // a is longer
            return false;
        }else{ // a == b
            return true;
        }
    }
};