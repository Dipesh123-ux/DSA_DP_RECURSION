#include<bits/stdc++.h>
using namespace std;

int jumpLadder(int n){
    if(n == 0) return 1;

    if(n < 0){
        return 0;
    }

    return jumpLadder(n-1) + jumpLadder(n-2) + jumpLadder(n-3);
}


int main(){

    int n;
    cin>>n;

    cout<<jumpLadder(n);

}