#include<bits/stdc++.h>
using namespace std;

char words[][10] =  {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpelling(int n){
      
      if(n == 0){
          return;
      }

    printSpelling(n/10);
    int k = n % 10;
    cout<<words[k]<<" ";
    return;
}

int main(){

    int n;
    cin >> n;

    printSpelling(n);

}