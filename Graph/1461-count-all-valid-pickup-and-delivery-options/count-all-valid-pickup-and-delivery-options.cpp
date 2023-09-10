class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans*i*(2*i-1)%mod;
            ans = ans%mod;
        }
        return ans;
    }
};