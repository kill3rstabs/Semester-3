#include <iostream>
using namespace std;
#define N 4
//I am solving Nqueen but who's my queen ?
void printBoard(int board[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;i<4;j++){
            cout<<"{"<<board[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
}
bool isSafe(int board[N][N],int row,int col){
    if(board[row-1][col]==-1 ||     board[row+1][col+1]==-1){
        return false;
    }
    else{
        return true;
    }
}
bool NQueen(int board[N][N],int row){
    if(row == N){
        return true;
    }
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
        return true;
        }
        if(NQueen(board,row+1)){ //true 
            board[row][col]=1;
            for(row; row<N;row++){
                board[row][col]=-1;
            }
            for(row,col;row<N,col<N;row++,col++){
                board[row][row] = -1;
            }
            return true;
        }
        board[row][col]=0;

    }
    return false;
    
}
int main(){
    int board[4][4]={0};
    NQueen(board,0);
	printBoard(board);

    return 0;
}
