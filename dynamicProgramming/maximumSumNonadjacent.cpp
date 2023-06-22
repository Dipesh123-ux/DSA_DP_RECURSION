#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
  
  vector<int> dp(n+1,0);
  dp[0] = arr[0];
  for(int i = 1; i < n; i++){
    
    int take = (i > 1) ? arr[i] + dp[i-2] : arr[i];
    int non_take = dp[i-1];

    dp[i] = max(take,non_take);
      
  }

    cout<<dp[n-1]<<endl;

}