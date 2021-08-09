#include <iostream>


class Solution {
public:
    vector<vector<string>> res;
    vector<string> restoreIpAddresses(string s) {
        vector<string> record;
        vector<string> r;
        findValidPart(s, 0, record);
        // 处理res的结果，拼接成字符串
        for(int j = 0; j < res.size(); j++){
            r.push_back(res[j][0] + "." + res[j][1] + "." + res[j][2] + "." + res[j][3]);
        }
        return r;
    }
    void findValidPart(string& s, int index, vector<string> record){
        //[0, index) 已经被处理过
        // 判断每一个用. 隔开的部分是不是valid
        // index 目前处理到的index
        // record: 储存上一层的所有有效的部分
        if(index >= s.size())
            return;
        for(int i=0; i<3; i++){
            string p = s.substr(index, i+1);
            if(index + i < s.size() && isValidIPPart(p)){
                vector<string> valid;
                valid.assign(record.begin(), record.end());
                valid.push_back(p);
                if(index+i+1 == s.size() && valid.size() == 4){
                    // reach the end of string and exactly 4 parts
                    res.push_back(valid);
                }

                if(valid.size() >= 4)
                    continue;
                findValidPart(s, index+i+1, valid);
            }
        }
    }
    bool isValidIPPart(string s){
        string temp = s;
        int temp_i = atoi(temp.c_str());
        if(temp_i == 0 && temp.size() != 1){
            return false;
        }
        if(temp_i != 0 && temp[0] == '0'){ // with leading zero
            return false;
        }
        if(temp_i > 255)
            return false;
        return true;
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
