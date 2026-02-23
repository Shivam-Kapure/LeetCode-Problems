class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = prices[0];
        int max = 0;
        int len = prices.size();

        for(int p : prices) {
            if(start < p)
                max += p - start;
            start = p;
        }
        return max;
    }
};