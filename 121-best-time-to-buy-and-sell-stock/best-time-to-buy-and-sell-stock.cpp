class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; int right = 1;
        int max_profit = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                max_profit = max(profit, max_profit);
                right++;
            }
            else {
                left = right;
                right++;
            }
        }
        return max_profit;
    }
};