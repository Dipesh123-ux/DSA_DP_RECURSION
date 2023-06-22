#include<bits/stdc++.h>
using namespace std;

// top down dp

//recursion + memoisation

int fib(int n , int dp[]){
    if(n == 0 || n == 1) return n;

    if(dp[n] != 0){
        return dp[n];
    }
 
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// bottom up approach

int fibBIU(int n){

    int dp[100] = {0};
    dp[1] = 1;


    for(int i=2; i <n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n-1];

}

// bottom up approach with space optimization

int fibSpace(int n){
    if(n == 0 || n == 1) return n;

    int a = 0, b = 1;
    int c;
    for(int i =2; i <= n ; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main(){

    int n;
    cin>>n;

    // int dp[100] = {0};

    cout<<fibSpace(n);

}