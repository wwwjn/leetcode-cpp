#include <iostream>

class ValidWordAbbr {
private:
    unordered_map<string, set<string>> record;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i = 0; i< dictionary.size(); i++){
            string word = dictionary[i];
            string abbr;
            if(word.size() == 2)
                abbr = word;
            else
                abbr = word[0] + to_string(word.size() - 2) + word[word.size()-1];

            if(record.find(abbr) == record.end()){
                set<string> tmp;
                tmp.insert(word);
                record.insert(make_pair(abbr, tmp));
            }else{
                cout << word << endl;
                record[abbr].insert(word);
            }
        }
    }

    bool isUnique(string word) {
        string abbr;
        if(word.size() == 2)
            abbr = word;
        else
            abbr = word[0] + to_string(word.size() - 2) + word[word.size()-1];
        if(record.find(abbr) == record.end())
            return true;
        if(record[abbr].find(word) != record[abbr].end() && record[abbr].size() == 1)
            return true;

        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
