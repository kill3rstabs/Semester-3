#include <iostream>
#define N 4
using namespace std;
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
  
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}
bool solveNqueen(int board[N][N],int row){
	if(row==N){
		printSolution(board);
		return true;
		
	}
	for(int col=0;col<N;col++){
		if(isSafe(board,row+1,col)){
			board[row][col] = 1;
			if(solveNqueen(board,row+1)){
				return true;
			}
			board[row][col] =0;
		}	
	}
	cout<<"false";
	return false;
}
int main(){
	int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    solveNqueen(board,0);
	

}
