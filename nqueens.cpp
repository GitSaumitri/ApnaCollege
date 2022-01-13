#include<iostream>
using namespace std;

bool isSafe(int **arr, int row, int col, int n){
    
    for(int r=0; r<row; r++){
        if(arr[r][col]==1)
            return false;
    }

    int x = row;
    int y = col;
    while(x>=0 && y>= 0){
        if(arr[x][y]==1)
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;
    while(x>=0 && y<n){
        if(arr[x][y]==1)
         return false;
        x--;
        y++; 
    }
    return true;
}

bool nQueens(int **arr, int x, int n){
    
    if(x>=n){
        return true;
    }

    for(int col=0; col<n; col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueens(arr,x+1,n)){
                return true;
            }

            arr[x][col]=0; //backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Give the queen board size :";
    cin>>n;

    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }

    if(nQueens(arr,0,n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }       
    return 0;
}