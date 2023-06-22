#include<bits/stdc++.h>
using namespace std;

int friendsProblem(int n){
    if(n == 0 or n == 1) return 1;

    return friendsProblem(n-1) + (n-1)*friendsProblem(n-2);
}

int main(){

    // n number of people having n bikes can go single or as a couple 

    int n;
    cin>>n;

    cout<<friendsProblem(n);

}