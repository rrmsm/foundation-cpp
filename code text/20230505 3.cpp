//733. 图像渲染
class Solution {
public:
    const int dx[4] = {1,0,0,-1};
    const int dy[4] = {0,1,-1,0};

    void dfs(vector<vector<int>>& image, int x, int y, int color, int newcolor){
        if(image[x][y] == color){
            image[x][y] = newcolor;
        }
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size() && image[mx][my] == color){
                dfs(image, mx, my, color, newcolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(oldcolor == color) return image;
        dfs(image, sr, sc, oldcolor, color);
        return image;
    }
};