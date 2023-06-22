
#include<bits/stdc++.h>
using namespace std;

void allOcuurance(int *a,int i , int n , int key){
    if(i == n){
        return;
    }
    if(a[i]==key){
        cout<<i<<" ";
    }
    allOcuurance(a,i+1,n,key);
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<firstOccurance(arr,n,key);
    cout<<" ";
    cout<<lastOccurance(arr,n,key);


}