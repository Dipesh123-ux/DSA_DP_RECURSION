#include<bits/stdc++.h>
using namespace std;

int main(){

    string num;
    cin>>num;

     char ans = '0' ;
     char s = num[0];
     int c = 1;
        
        for(int i = 1 ; i < num.length()-2;i++){
            
            if(num[i] == s){
                c++;
                if(c == 3){
                   ans = max(ans,s);
                   c = 1; 
                }
            }
            else{
                c = 1;
                s = num[i];
            }
            
        }

  string a(1,ans);     

cout<<a+a+a<<endl;


}