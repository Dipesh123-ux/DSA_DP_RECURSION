#include<bits/stdc++.h>
using namespace std;

int minCoins(int n, int coins[],int T,int dp[]){
    if(n == 0){
        return 0;
    }

    int ans = INT_MAX;

    if(dp[n] != 0){
        return dp[n];
    }

    for(int i =0; i < T; i++){ 

   if(n- coins[i] >= 0){
        int subProb = minCoins(n-coins[i],coins,T,dp);

        ans = min(ans,subProb + 1);
   }

    }

    dp[n] = ans;
    return dp[n];
}

int minCoinsBU(int N , int coins[],int T){
    int dp[100] = {0};

   for(int n = 1; n <= N; n++){

    int ans = INT_MAX;
      
    for(int i = 0;i < T;i++){
        
        if(n - coins[i] >= 0){
            dp[n] = dp[n-coins[i]];
            ans = min(ans,dp[n] + 1);
        }

        dp[n] = ans;
    }   
   }

   return dp[N];    
}



int main(){

    int n;
    cin>>n;
    int coins[] = {1,3,5};

    int dp[100] = {0};

    // cout<<minCoins(n,coins,10,dp); 
    cout<<minCoinsBU(n,coins,3); 

}