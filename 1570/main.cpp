#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class SparseVector {
private:
    unordered_map<int, int> record;
    int s;
public:

    SparseVector(vector<int> &nums) {
        s = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                record.insert({i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(auto r = record.begin(); r!= record.end(); ++r){
            int index = r->first;
            if(vec.getNum(index) != 0){
                res += vec.getNum(index) * r->second;
            }
        }
        return res;
    }
    int getNum(int index){
        if(record.find(index) != record.end()){
            return record[index];
        }else
            return 0;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);