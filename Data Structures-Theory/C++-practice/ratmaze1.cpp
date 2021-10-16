// rat maze part 2 
#include <iostream>
#define N 7
using namespace std; 
bool isSafe(int maze[N][N],int row,int col){
	if(maze[N][N]==0){
		return false;
	}
	return true;
}
bool ratMaze(int maze[N][N],int row,int path[N][N]){
	if(row == N){
		return true;
	}
	for(int col = 0;col<N;col++){
		if(isSafe(maze,row,col)){
			path[col][row]= 1;
			if(ratMaze(maze,row+1,path)){
				return true;
			}
			path[row][col] = 0;
		}	
		
	}
	return false;
}
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
int main(){
	int maze[N][N];
	int path[N][N]={0};
	ratMaze(maze,0,path);
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           cin>>maze[i][j];
    }
	printSolution(path);
	
	return 0;
}
