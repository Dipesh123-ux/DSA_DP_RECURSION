#include<bits/stdc++.h>
using namespace std;

void permute(char *in,int i){
    if(in[i] == '\0'){
        cout<<in<<" ";
        return;
    }

    for(int j=i;in[j] != '\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1);
        // backtracking to restore the original state of the array
        swap(in[i],in[j]);
    }

    return;
}

int main(){
 
 char in[100];
 cin>>in;
 permute(in,0);

}