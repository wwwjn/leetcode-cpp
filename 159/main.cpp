#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() == 1)
            return 1;
        map<char, int> record;
        int i = 0;
        int j = 1;  // [i..j];
        record.insert({s[i], 1});
        if(record.find(s[j]) == record.end()){
            record.insert({s[j], 1});
        }else{
            record[s[j]] ++;
        }
        int maxSize = 0;
        while(j < s.size()){
            if(record.size() <= 2){
                maxSize = max(maxSize, j-i+1);
                // move j
                j++;
                if(record.find(s[j]) == record.end())
                    record.insert({s[j], 1});
                else
                    record[s[j]]++;
            }
            else{
                // delete s[i] from record;
                if(record[s[i]] == 1){
                    record.erase(s[i]);
                }else{
                    record[s[i]]--;
                }
                i++;
            }
        }
        return maxSize;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
