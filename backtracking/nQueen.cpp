#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][100],int i,int j,int n){

    for(int row = 0 ; row < i ; row++){
            if(board[row][j] == 1){
                 return false;
            }
    }  

    int x = i;
    int y = j;

    //check for left diagonal

   
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    //check for right diagonal

    x = i;
    y = j;
    while(x >= 0 && y < n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    return true;

}

bool solveNQueen(int board[][100],int i ,int n){

    // base case

    if(i == n){

        //you have successfully placed the queens in n rows
        //print the board and
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < n ; j++){
                if(board[i][j] == 1){
                    cout<<"Q"<<" ";
                }
                else{
                   cout<<"_ ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    // recursive case
// try to place the queen in the current row and call the remaining part recursively


    for(int j = 0; j < n; j++){
        if(isSafe(board,i,j,n)){

            // place the queen , assuming i,j is the right position to place the queen
             board[i][j] = 1;
             bool nextQueen =  solveNQueen(board,i+1,n);
             if(nextQueen){
                 return true;
             }

             // means i ,j is not the right position to place the queen and our assumption is wrong

             board[i][j] = 0;  //backtrack
        }

    }


//you have tried all the possible positions in the current row but couldn't place a queen

   return false;


}


int main(){

    int n;
    cin >> n;

    int board[100][100] = {0};

    solveNQueen(board,0,n);

}