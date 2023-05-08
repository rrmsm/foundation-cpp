//994. 腐烂的橘子
class Solution {
public:
    static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.emplace(i, j);
                }
            }
        }
        while(!q.empty()){
            queue<pair<int, int>> newq;
            int num1 = q.size();
            for(int f = 0; f < num1; f++){
                auto [i, j] = q.front();
                q.pop();
                for(int s = 0; s < 4; s++){
                    int mi = i + dirs[s][0];
                    int mj = j + dirs[s][1];
                    if(mi >= 0 && mj >= 0 && mi < m && mj < n && grid[mi][mj] == 1){
                        grid[mi][mj] = 2;
                        newq.emplace(mi, mj);
                    }
                }
            }
                if(newq.empty()) break;
                int num2 = newq.size();
                for(int k = 0; k < num2; k++){
                    auto [temp1, temp2] = newq.front();
                    newq.pop();
                    q.emplace(temp1, temp2);
                }               
           minute += 1; 
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
        }
    }
    return minute;
    }
};