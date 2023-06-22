#include<bits/stdc++.h>
using namespace std;

void generateBrackets(char *out,int n,int idx , int op,int cl){
    if(idx == 2*n){ 
        out[idx] = '\0';
        cout<<out<<endl;
        return;
    }

   if(op < n){
       out[idx] = '(';
       generateBrackets(out,n,idx+1,op + 1,cl);
   }
   if(cl < op){
       out[idx] = ')';
       generateBrackets(out,n,idx+1,op,cl+1); 
   }

   return;

}

int main(){

    int n;
    cin >> n;

    char out[1000];

    int idx = 0;

    generateBrackets(out,n,idx,0,0);

}