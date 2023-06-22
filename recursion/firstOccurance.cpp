 #include<bits/stdc++.h>
using namespace std;

int lastOccurance(int *a,int n,int key){
    if(n == 0) return -1;

    int ans = lastOccurance(a+1,n-1,key);

    if(ans == -1){
        if(a[0] == key) return 0;
        return -1;
    }

    return ans + 1;

}

int firstOccurance(int *a,int n , int key){
    if(n==0){
        return -1;
    }

    if(a[0] == key){
        return 0;
    }

    int ans = firstOccurance(a+1,n-1,key);

    if(ans==-1){
        return -1;
    }
    return ans+1;
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