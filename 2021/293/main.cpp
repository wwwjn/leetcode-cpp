#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for(int i = 0; i < currentState.size()-1; i++){
            if(currentState[i] == '+' && currentState[i+1] == '+'){
                string newState = currentState;
                newState[i] = '-';
                newState[i+1] = '-';
                res.push_back(newState);
            }
        }
        return res;

    }
};