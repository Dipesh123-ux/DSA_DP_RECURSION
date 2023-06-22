#include<bits/stdc++.h>
using namespace std;

void subsets(string in,char *out,int i ,int j ){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<" ";
        return;

    }

    // include the current character 

    out[j] = in[i];
    subsets(in,out,i+1,j+1);

   // exclude  the current character

     subsets(in,out,i+1,j);

}

int main(){

    string s;
    cin>>s;

   char output[100];

   subsets(s, output,0,0);


}