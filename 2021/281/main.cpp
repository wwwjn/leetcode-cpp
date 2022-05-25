#include <iostream>
using namespace std;

class ZigzagIterator {
private:
    int i;
    int j;
    vector<int> v1;
    vector<int> v2;
    bool flag; // flag = 1(true) or 2(false)
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        i = 0;
        j = 0;
        flag = true;
    }

    int next() {
        if(flag){
            if(i < v1.size()){
                // choose from v1
                int res = v1[i++];
                flag = false;
                return res;
            }else{ // i arrives the end of v1;
                flag = false;
                int res = v2[j++];
                return res;
            }
        }else{
            if(j < v2.size()){
                // choose from v2
                int res = v2[j++];
                flag = true;
                return res;
            }else{  // j arrives the end of v2
                flag = true;
                int res = v1[i++];
                return res;
            }
        }
    }

    bool hasNext() {
        return i < v1.size() || j < v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
