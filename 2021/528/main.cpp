#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    int total = 0;
    vector<int> record;
public:
    Solution(vector<int>& w) {
        record.resize(w.size());
        for(int i = 0; i < w.size(); i++){
            total += w[i];
            record[i] = total;
        }
    }

    int pickIndex() {
        // random from [0..total];
        int num = rand() % total;
        cout<< num << endl;
        return find(num, 0, record.size()-1);
    }
    int find(int x, int start, int end){
        // find x's position in the box from [start...end];
        if(start == end)
            return start;
        int mid = start + (end - start) / 2;
        if(x < record[mid]){
            return find(x, start, mid);
        }else{
            return find(x, mid+1, end);
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */