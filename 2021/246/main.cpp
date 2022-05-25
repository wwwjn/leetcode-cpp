#include <iostream>


class Solution {
private:
    unordered_map<int,int> record;
public:
    bool isStrobogrammatic(string num) {
        record.insert({8,8});
        record.insert({6,9});
        record.insert({9,6});
        record.insert({1,1});
        record.insert({0,0});
        int i = 0;
        int j = num.size()-1;
        while(i<=j){
            if(record.find(num[i]-'0')!=record.end()){
                if(record[num[i]-'0'] == (num[j]-'0')){
                    i++;
                    j--;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
