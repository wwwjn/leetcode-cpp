#include <iostream>
#include <map> // ordered
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> record;
        for(int i = 0; i < s.size(); i++){
            if(record.find(s[i]) == record.end())
                record.insert(make_pair(s[i], 1));
            else record[s[i]] ++ ;
        }
        multimap<int, char> reverse;
        for(unordered_map<char,int>::iterator it = record.begin(); it != record.end(); it++){
            reverse.insert(make_pair(it->second, it->first));
        }
        string res = "";
        for(multimap<int,char>::reverse_iterator it = reverse.rbegin() ; it != reverse.rend(); it ++){
            int times = it->first;
            for(int j = 0; j < times; j++){
                res += it->second;
            }
        }
        return res;

    }
};


int main() {
    cout << Solution().frequencySort("cacaca") << endl;
    return 0;
}
