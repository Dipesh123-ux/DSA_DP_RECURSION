class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prev = INT_MAX;
        for(int i = 0; i < prices.size();i++){
            prev = min(prev,prices[i]);
            profit = max(profit,prices[i]-prev);
        }

        return profit;
    }
};