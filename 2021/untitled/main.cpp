#include <iostream>

// input: list of number , int X
// output: the occurrences of X, int

# include "vector"
using namespace std;

class Solution{
public: int findOccurrences(vector<int> nums, int X){
        int retval = 0;  // for return result
        // suppose: from less to greater
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == X) {
                retval++;
            }
            else if(nums[i] > X){
               break;
            }
        }
        return retval;
    }
};

int main() {
    vector<int> test = vector<int>();
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(3);
    int res = Solution().findOccurrences(test, 2);
    cout << "The result is " << res << endl;
}
