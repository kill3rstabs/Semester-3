#include <iostream>
using namespace std;

int main(){
	int magicsquare[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	magicsquare[0][1]=1;
	int row = 0;
	int col = 1;
	
	for(int i=2;i<=11;i++){
		row--;
		col++;
		if(magicsquare[row][col] ==0){
			if(row <0){
			row =2;
			}
			if(col>2){
				col =0;
			}
		}
		
		if(magicsquare[row][col] != 0){
			int temp;
			temp = row;
			row = col;
			col = temp;
			row++;
			
			
		}
		magicsquare[row][col]=i;
		
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<magicsquare[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	
	return 0;
}
