#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            res += (to_string(s.size()) + "/" + s);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while(!s.empty()){
            int found = s.find("/");
            int len = stoi(s.substr(0, found));
            s = s.substr(found+1); // delete the "/"
            res.push_back(s.substr(0, len));
            s = s.substr(len);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));