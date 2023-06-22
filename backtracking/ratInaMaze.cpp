#include<bits/stdc++.h>
using namespace std;

 bool ratInaMaze(char maze[10][10],int sol[][10],int i,int j,int m , int n){
     if(i == m && j == n){
         sol[m][n] = 1;
         for(int i=0; i<=m; i++){
             for(int j=0; j<=n; j++){
                 cout<<sol[i][j]<<" ";
             }
             cout<<endl;
         }

         cout<<endl;

         return true;
              }

              // rat should be inside the grid
              if(i > m || j >n){
                  return false;
              }

              if(maze[i][j] == 'X'){
                  return false;
              }

              // assume solution exist through the current cell

              sol[i][j] = 1;

              bool rightSuccess = ratInaMaze(maze, sol,i,j+1,m,n);
              bool downSuccess = ratInaMaze(maze, sol,i+1,j,m,n);

              sol[i][j] = 0;

              if(rightSuccess || downSuccess){
                  return true;
              }

              return false;

 }

int main(){

    char maze[10][10] = {
                        "000X",
                        "00X0",
                        "000X",
                        "0X00",
                        };

int sol[10][10] = {0};

bool ans = ratInaMaze(maze, sol,0,0,3,3);

if(ans == false){
    cout<<"Path doesn't exits"<<endl;
}
else{
    cout<<"These are the Possible paths"<<endl;
}


}