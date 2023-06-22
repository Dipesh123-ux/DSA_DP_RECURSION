#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n == 0) return;
     cout<<n<<" ";
     print(n-1);
    
}

int sum(int n){
    if(n == 0) return 0;
    return n + sum(n-1);
}

void printsub(int i,int arr[],int n,vector<int> v){
    if(i >= n) {
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    
    v.push_back(arr[i]);
    printsub(i+1,arr,n,v);
    v.pop_back();
    printsub(i+1,arr,n,v);

}

void sum_of_subsequence_with_sum_k(int i, int k, int sum, vector<int> v, int arr[],int n,int &c){
    if(i == n){
        if(k == sum){
            c++;
            for(int i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return ;
    }
    
    k += arr[i];
    v.push_back(arr[i]);
    sum_of_subsequence_with_sum_k(i+1,k,sum,v,arr,n,c);
    k -= arr[i];
    v.pop_back();
    sum_of_subsequence_with_sum_k(i+1,k,sum,v,arr,n,c);
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i < n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    vector<int> v;
    int c = 0;
    printsub(0,arr,n,v);
    // sum_of_subsequence_with_sum_k(0,0,sum,v,arr,n,c);
    cout<<c<<endl;

}