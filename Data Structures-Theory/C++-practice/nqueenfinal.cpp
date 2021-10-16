#include <iostream>
#define N 4
using namespace std;
int board[N][N]={0};
bool isSafe(int row,int col){
	int r, c;

  /*
    this function will check if the position is safe
    for the queen.

    we need to check the rows and the diagonals
   */
  

  /*
    if there is a queen in the given row
    then it is not a safe position
   */
  for(c = 0; c < col; c++) {
    if(board[row][c] == 1) {
      return false;
    }
  }

  /*
    check upper diagonal
   */
  for(r = row, c = col; r >= 0 && c >= 0; r--, c--) {
    if(board[r][c] == 1) {
      return false;
    }
  }

  /*
    check lower diagonal
   */
  for (r = row, c = col; c >= 0 && r < N; r++, c--) {
    if (board[r][c] == 1) {
      return false;
    }
  }
}
void print()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
bool NQ(int col){
	if(col==N-1){
		print();
		return true;
	}
	for(int row=0;row<N;row++){
		if(isSafe(row,col)){
			board[row][col]==1;
			if(NQ(col+1)){
				return true;
			}
			board[row][col]=0;
		}
	}
	return false;
}
int main(){
	
	
	return 0;
}
