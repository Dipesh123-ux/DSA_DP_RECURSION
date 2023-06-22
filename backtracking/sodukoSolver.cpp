#include<bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9],int i ,int j,int n,int num){
    for(int x = 0;x < n;x++){
        if(mat[x][j] == num || mat[i][x] == num){
            return false;
        }
    }

    int rn = sqrt(n);

    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx; x < sx + rn;x++){
        for(int y = sy; y < sy + rn; y++){
            if(mat[x][y] == num){
                return false;
            }
        }
    }

    return true;
}

bool solveSuduko(int mat[][9],int i ,int j,int n){
    if(i == n){
        //print the result

        for(int i = 0; i <n; i++){
            for(int j = 0 ; j <n ; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

        return true;
    }

    if(j == n){
       return solveSuduko(mat,i+1,0,n);
    }

    if(mat[i][j] != 0){
        return solveSuduko(mat,i,j+1,n);
    }

    for(int num = 1; num <= n; num++){
        if(canPlace(mat,i,j,n,num)){
            mat[i][j] = num;

            bool couldSolve = solveSuduko(mat,i,j+1,n);

            if(couldSolve == true){
                return true;
            }
        }
    }

    // backtrack

    mat[i][j] = 0;

    return false;


}

int main(){

    int mat[9][9] ={

        {6,1,4,0,8,7,0,0,0},
        {0,0,0,4,3,0,7,0,1},
        {5,0,0,0,0,0,0,8,0},
        {0,0,7,3,0,0,0,0,0},
        {4,0,0,0,0,2,8,0,5},
        {2,0,1,0,0,0,0,7,6},
        {0,4,2,0,7,6,5,1,9},
        {0,8,9,5,2,3,0,4,7},
        {0,6,5,1,0,0,0,0,0}
    
    };

      cout<<solveSuduko(mat,0,0,9);

      return 0;

}