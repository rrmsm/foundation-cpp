//122. 买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miner = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            miner = min(miner, prices[i]);
            if(prices[i] > miner){
                if(i != prices.size() - 1 && prices[i+1] < prices[i]){
                    res += prices[i] - miner;
                    miner = INT_MAX;
                }
                else if(i == prices.size() - 1){
                    res += prices[i] - miner;
                }
                else continue;
            }
        }
        return res;
    }
};