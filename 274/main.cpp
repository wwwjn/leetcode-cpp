#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        for(int h = citations.size()-1; h >= 0; h--){
            if(citations.size()-h <= citations[h]){
                int newh = citations.size()-h;
                res = max(res, newh);
            }
        }
        return res;
    }
};