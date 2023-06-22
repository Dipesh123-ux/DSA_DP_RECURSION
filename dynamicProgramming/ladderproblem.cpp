#include<bits/stdc++.h>
using namespace std;

int ways(int n , int k , int dp[]){
    if(n == 0){
        return 1;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int way = 0;

    for(int i = 1 ;i <= k;i++){
        if(n - i >= 0){
           way += ways(n-i,k,dp);
        }
    }

    return dp[n] = way;
}


int waysBU(int n,int k){
    int dp[100] = {0};

    dp[0] = 1;

    for(int i = 1; i <= n;i++){
        dp[i] = 0;

        for(int j = 1; j <= k;j++){
            if(i - j >= 0){
                dp[i] += dp[i-j];
            }
        }
    }

    return dp[n];
}

int ladders_optimised(int n ,int k){
    int dp[100] = {0};

    dp[0] = dp[1] = 1;

    for(int i = 2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }
    for(int i = k  + 1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k- 1];
    }     

    return dp[n];
}

int main(){

    int n , k;
    cin >> n >> k;

    int dp[100] = {0};

    cout<<ways(n,k,dp);
    cout<<waysBU(n,k);

}