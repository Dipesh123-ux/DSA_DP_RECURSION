#include<bits/stdc++.h>
using namespace std;

int main(){

      int num ,k;
      cin>>num>>k;

        string s = to_string(num);
        cout<<s;
        int count = 0;

        cout<<s.substr(0,2)<<" ";
        cout<<s.substr(1,2)<<" ";
        cout<<s.substr(2,2)<<" ";
        
        // for(int i = 0; i < s.length()-k + 1;i++){
        //     int a = stoi(s.substr(i,i+k));
        //     cout<<a<<" ";
            
        //     if(a != 0){
        //     if(num % a == 0){
        //         count++;
        //     }
        //     }
        // }

}