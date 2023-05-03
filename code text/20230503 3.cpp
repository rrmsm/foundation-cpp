//120. 三角形最小路径和
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        vector<int> dp(n+1, 0);//只是计算当前层每一个点的最小值，自下而上
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};