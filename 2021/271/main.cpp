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




class Solution {
private:
    int m, n;
    int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    bool inArea(int x, int y){
        return x< m && x >=0 && y<n && y >=0;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // bfs (x,y)
            for(int k = 0; k < 4; k++){
                int newx = x + d[k][0];
                int newy = y + d[k][1];
                if(inArea(newx, newy) && rooms[newx][newy]!=-1 && rooms[newx][newy]!= 0){
                    if(rooms[newx][newy] < rooms[x][y] + 1)
                        continue;
                    rooms[newx][newy] = rooms[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));