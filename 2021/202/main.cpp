#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        //记录有没有循环
        unordered_set<int> record;
        int current_num = n;
        while(record.find(current_num) == record.end() && current_num != 1){
            record.insert(current_num);
            int sum = 0;
            int temp_num = current_num;
            int num = (int)(temp_num % 10);
            sum += num * num;
            while(((temp_num - num)/10)!= 0){
                temp_num = (temp_num - num)/10;
                num = temp_num % 10;
                sum += num * num;
            }
            current_num = sum;
        }
        if(current_num == 1)
            return true;
        else return false;
    }
};

int main() {
    cout << (bool)Solution().isHappy(2) << endl;
    return 0;
}
