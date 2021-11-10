#include <iostream>
#define N 3
using namespace std;
int grid[N][N]={{1,1,1},{1,0,1},{1,1,1}};
int path[N][N]={0};
bool isSafe(int grid[N][N],int i,int j) {
	if(grid[i][j]==1){
		return true;
	}
	return false;
}
bool robotPath(int grid[N][N],int i,int j){
	static int count =0;
	if(i==N-1 && j==N-1){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<path[i][j]<<" ";
			}
			cout<<endl;
		}
		
		exit(0);
		return false;
	}
		if(isSafe(grid,i,j)){ // checking if the path is safe or not
			path[i][j]=1;
			if(robotPath(grid,i,j+1)){ //rat moving right
				return true;
			}
			if(robotPath(grid,i+1,j)){ //rat moving downwards
				return true;
			}
		}
		return false;
	
}


int main(){
	robotPath(grid,0,0);
	return 0;
}
