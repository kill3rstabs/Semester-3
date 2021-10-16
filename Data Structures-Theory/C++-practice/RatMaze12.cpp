#include <iostream>
#define N 4
using namespace std;

int maze[N][N]={{1,0,0,1},
				{1,1,0,0},
				{0,1,1,0},
				{1,0,1,1}
};
int path[N][N]={0};
void print() {
  int r, c;
  for(r = 0; r < N; r++) {
    for(c = 0; c < N; c++) {
      printf("%d ", path[r][c]);
    }
    printf("\n");
  }
}
bool isSafe(int row,int col){
	if(maze[row][col]==0 || row<0 || col<0 || row>N|| col>N){
		return false;
	}
	return true;
}
bool RatMaze(int row,int col ){
	if(row>= 3 && col>=3){
		print();
		return true;
	}
	if(isSafe(row,col)){
		path[row][col]=1;
		if(RatMaze(row+1,col)){
			return true;
		}
		else if(RatMaze(row,col+1)){
			
			return true;
			
		}
		else if(RatMaze(row-1,col)){
			return true;
		}
		else if(RatMaze(row,col+1)){
			return true;
		}
		path[row][col]=0;
	}
	return false;
}
int main(){
	RatMaze(0,0);
	
	return 0;
}
