#include <iostream>
#define N 4
using namespace std;
int board[N][N]={0};
void print() {
  int r, c;
  for(r = 0; r < N; r++) {
    for(c = 0; c < N; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}
bool isSafe(int row,int col){
	for(int j=0;j<N;j++){
		if(board[row][j]==1){
			return false;
		}
	}
	for(int i = row,j=col;i>=0 && col>=0;i--,j--){
		if(board[i][j]==1){
			return false;
		}
	}
	for(int i= row,j=col; i>=N && col>=0;i++,j--){
		if(board[i][j]==1){
			return false;
		}
		
	}
	return true;
}
bool NQueen(int col){
	if(col>=N){
		print();
		return true;
	}
	for(int row=0;row<N;row++){
		if(isSafe(row,col)){
			board[row][col]=1;
			if(NQueen(col+1)){
				return true;
			}
			board[row][col]=0;
		}
		
	}
	return false;
}
int main(){
	NQueen(0);
	
	return 0;
}
