#include<bits/stdc++.h>
using namespace std;

int powFast(int a , int n){
    if(n == 0){
        return 1 ;
    }

    int smaller_ans = powFast(a, n/2);
    smaller_ans *= smaller_ans;
    if(n&1){
        return a*smaller_ans;
    }

    return smaller_ans;

}

int main(){

    int a , n;
    cin>>a>>n;

    cout<<powFast(a,n);



}