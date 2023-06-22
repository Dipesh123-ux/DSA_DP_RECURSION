#include<bits/stdc++.h>
using namespace std;

int waysOfplacing(int n){
    if(n <= 3){
        return 1;
    }

    return  waysOfplacing(n-1) + waysOfplacing(n-4);
}

int main(){

// size of 4 x n wall

int n;
cin>>n;

cout<<waysOfplacing(n)<<endl;


}