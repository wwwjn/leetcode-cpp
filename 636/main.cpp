#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = -1;
        for(string log: logs){
            int found1 = log.find(":");
            int found2 = log.find_last_of(':');
            int idx = stoi(log.substr(0, found1));
            string type = log.substr(found1 + 1, found2 - found1 - 1);
            int time = stoi(log.substr(found2 + 1));
            if(!st.empty()){
                res[st.top()] += (time - prevTime);
            }
            prevTime = time;
            if(type == "start")
                st.push(idx);
            else{  // end
                auto t = st.top();
                st.pop();
                ++res[t];
                // 注意对end的处理
                ++prevTime;
            }
        }
        return res;
    }
};