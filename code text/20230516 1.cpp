//54. 螺旋矩阵class Solution {public:    vector<int> spiralOrder(vector<vector<int>>& matrix) {        int m = matrix.size(), n = matrix[0].size();        vector<int> v;        int i = 0, j = m-1, l = 0, r = n-1;        while(true){            for(int temp = l; temp <= r; temp++) v.emplace_back(matrix[i][temp]);            if(++i > j) break;//第一行用完了，更新上边界            for(int temp = i; temp <= j; temp++) v.emplace_back(matrix[temp][r]);            if(--r < l) break;//最后一列用完了，右边界            for(int temp = r; temp >= l; temp--) v.emplace_back(matrix[j][temp]);            if(--j < i) break;//下边界            for(int temp = j; temp >= i; temp--) v.emplace_back(matrix[temp][l]);            if(++l > r) break;//左边界        }        return v;    }};