//121. 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min1 = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            min1 = min(prices[i], min1);
            res = max(prices[i] - min1, res);
        }
        return res;
    }
};