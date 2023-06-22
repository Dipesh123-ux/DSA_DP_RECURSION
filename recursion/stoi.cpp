#include<bits/stdc++.h>
using namespace std;

int stringtointeger(string s,int n){
    if(n == 0) {
        return 0;
    }

    int digit = s[n-1] - '0';
   int smaller_ans = stringtointeger(s,n-1);

    return smaller_ans*10 + digit;

}

int main(){

 string s;
cin >> s;

cout<<stringtointeger(s,s.length());

}