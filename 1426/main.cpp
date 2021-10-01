#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> record;
        for(int i = 0; i< arr.size(); i++){
            if(record.find(arr[i]) == record.end())
                record.insert({arr[i],1});
            else
                record[arr[i]]++;
        }
        int count = 0;
        for(auto r: record){
            if(record.find(r.first+1) != record.end()){
                count += record[r.first];
            }
        }
        return count;
    }
};