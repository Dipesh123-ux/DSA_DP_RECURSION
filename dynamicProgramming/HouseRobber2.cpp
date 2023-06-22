#include <bits/stdc++.h> 
long long int solve(int n,vector<int> &nums){
    vector<long long int> dp(n+1);
    dp[0] = nums[0];
    for(int i = 1; i <= n;i++){
        long long int l = nums[i] + ((i>1) ? dp[i-2] : 0);
        long long int r = dp[i-1];
        dp[i] = max(l,r);
    }
    
    return dp[n];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> t1,t2;
    int n = valueInHouse.size();
    if(n == 0) return 0;
    if(n == 1) return valueInHouse[0];
    for(int i = 0; i < n;i++){
        if(i != 0) t1.push_back(valueInHouse[i]);
        if(i != n-1) t2.push_back(valueInHouse[i]);
    }
    long long int a1 = solve(n-2,t1);
    long long int a2 = solve(n-2,t2);
    long long int ans = max(a1,a2);
    return ans;
}