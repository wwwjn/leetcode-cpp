#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        string cur = sentence;
        while(cur.find(" ") != std::string::npos){
            int idx = cur.find(" ");
            string word = cur.substr(0, idx);
            words.push_back(word);
            cout << cur << endl;
            cur = cur.substr(idx+1, cur.size()-idx-1);
        }
        words.push_back(cur);
        string res= "";
        for(int i = 0; i< words.size(); i++){
            string word = words[i];
            cout << word<< endl;
            if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U'){
                word += "ma";
            }else{
                word = word.substr(1, word.size()-1) + word[0] + "ma";
            }
            for(int j = i; j >=0 ; j--){
                word += 'a';
            }
            res += word;
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};