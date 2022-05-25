#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};