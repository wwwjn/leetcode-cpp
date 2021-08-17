#include <iostream>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int c = 0;
        int begin = 0;
        int end = 0;
        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            c += (words[i].size() +1);
            if( (i+1) == words.size() || c + words[i+1].size() > maxWidth){
                string temp = fillWords(words, begin, i, maxWidth);
                res.push_back(temp);
                begin = i+1;
                c = 0;
            }

        }
        return res;
    }
    string fillWords(vector<string>& words, int begin, int end, int maxWidth){
        // [begin, end]:
        bool isFinal = (end == words.size() -1);
        int count = end - begin + 1;
        int whiteCount = maxWidth;
        string res;
        for(int i = begin; i <= end; i++){
            whiteCount -= words[i].size();
        }
        if(isFinal){
            cout << isFinal;
            for(int i = begin; i<= end; i++){
                res += words[i];
                if(i != end)
                    res += " ";
            }
            while(res.size() < maxWidth){
                res += " ";
            }
            return res;
        }
        // not Final
        if(count == 1){
            res += words[begin];
            while(res.size() < maxWidth){
                res += " ";
            }
            return res;
        }
        int minWhite = whiteCount/(count-1); // round to zero;
        int lag = whiteCount - minWhite*(count - 1);
        for(int i = begin; i <= end; i++){
            res += words[i];
            int count = 0;
            while(count < minWhite && i != end){
                res += " ";
                count ++;
            }
            if(i - begin < lag){
                res += " ";
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
