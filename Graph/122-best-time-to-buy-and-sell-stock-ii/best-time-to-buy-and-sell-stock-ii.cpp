class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int b = 0;
        int s = 0;
  

        for(int i = 1; i < prices.size();i++){
            s = i;
            if(prices[i] < prices[i-1]){
            ans += (prices[s-1]-prices[b]);
                b = i;
            }
        }

        ans += prices[s] - prices[b];

        return ans;
    }
};