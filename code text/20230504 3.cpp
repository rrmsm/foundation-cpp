//135. 分发糖果
class Solution {
public:
//如果左边右边一起做，就会顾此失彼，只能一次做一边的。
//局部最优可以推出全局最优。
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n,1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                v[i] = v[i-1] + 1;
            }
        }

        for(int j = n-2; j >= 0; j--){
            if(ratings[j] > ratings[j+1]){//为什么要这样，因为这样子做每次都可以用到上一次的结果
                v[j] = max(v[j], v[j+1] + 1);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += v[i];
        }
        return ans;
    }
};