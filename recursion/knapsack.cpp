#include<bits/stdc++.h>
using namespace std;

int profit(int n,int c,int *weights,int *prices){
    if(n == 0 || c == 0){
        return 0;
    }

    int ans = 0;
    int inc , exc;
    inc = exc = 0;

    if(weights[n-1] <= c){

        inc = prices[n-1] + profit(n-1,c-weights[n-1],weights,prices);
    }

    exc = profit(n-1,c,weights,prices);
 
    ans = max(inc,exc);
    return ans;
}

int main(){

    int n;
    cin >> n;

   int weights[n],prices[n];

   for(int i=0; i <n; i++){
       cin>>weights[i]>>prices[i];
   }
  
  int c;
  cin >> c;

  cout<<profit(n,c,weights,prices);


}