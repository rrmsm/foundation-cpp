//322. 零钱兑换
class Solution {
public:
//好难/(ㄒoㄒ)/~~
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                    //INT_MAX相当于把没办法组成的数不遍历了
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};