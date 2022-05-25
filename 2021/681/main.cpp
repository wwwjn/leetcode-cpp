#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> s;
        set<char> record;
        for(int i = 0; i< time.size(); i++){
            if(time[i] == ':') continue;
            if(record.find(time[i]) == record.end()){
                s.push_back(time[i]);
                record.insert(time[i]);
            }
        }
        string HHMM = time.substr(0,2) + time.substr(3,2);
        sort(s.begin(), s.end());
        for(int i = 3; i>=0; i--){
            int j = 0;
            while(j< s.size() && s[j] != (HHMM[i])) j++;
            while(j+1 < s.size()){
                j++;
                HHMM[i] = s[j];
                if(HHMM.substr(0, 2) < "24" && HHMM.substr(2, 2) < "60"){
                    return HHMM.substr(0, 2) +":"+ HHMM.substr(2, 2);
                }
            }
            HHMM[i] = s[0];
        }
        return HHMM.substr(0, 2) +":"+ HHMM.substr(2, 2);
    }
};