#include <iostream>
#define N 4
using namespace std;
int grid[N][N]={{1,0,1,0},
				{0,0,1,1},
				{0,0,0,0},
	            {0,1,1,0}};

bool check_squares(int r,int c){
	static int count =0;
	//base condition 
	if(grid[r][c]==0 || r>N-1 || c>N-1){
		cout<<count;
		exit(0);
//		return false;
		
	}
	//
	if(grid[r][c]==1){
			count++;
		if(check_squares(r+1,c)){
			return true;
		}
		else if(check_squares(r,c+1)){
			return true;
		}
		else if(check_squares(r-1,c)){
			return true;
		}
		else if(check_squares(r,c-1)){
			return true;
		}
		//jump back to the position where you had come from
	}
	else{
		return false;
	}
	
	return false;
		
		
	};
int main(){
	
	int row,col;
	cin>>row>>col;
	check_squares(row,col);
	
	
}
