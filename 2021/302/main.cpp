#include <iostream>

class Solution {
private:
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    int m, n;
    vector<vector<bool>> visited;
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        m = image.size();
        n = image[0].size();
        xmin = x;
        xmax = x;
        ymin = y;
        ymax = y;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        findArea(image, x, y);
        return (xmax - xmin +1)*(ymax- ymin+1);
    }
    void findArea(vector<vector<char>>& image, int x, int y){
        // move another step from (x, y);
        visited[x][y] = true;
        for(int i = 0; i< 4; i++){
            int newx= x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && image[newx][newy] == '1' && !visited[newx][newy]){
                xmin = min(xmin, newx);
                ymin = min(ymin, newy);
                xmax = max(xmax, newx);
                ymax= max(ymax, newy);
                findArea(image, newx, newy);
            }
        }
    }
    bool inArea(int x, int y){
        return x>=0 && x<m && y>=0 && y< n;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
