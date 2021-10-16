#include <iostream>

using namespace std;

int main() {
	
	int box = 0;
	int arr[9][9];
	int flag[9]={0,0,0,0,0,0,0,0,0}; 
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<9;i++){
		arr[8][i]=0;
	}
	
	for(int i=0;i<9;i++){
		arr[i][8]=0;
	}
	
	
	
	

	for(int i=0;i<8;i++){
		box=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr[i][k])-1]=1;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==0){
				box=k+1;
				break;
			}
		}
			
		
		arr[i][8]=box;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=0;
		}
			
				
	}
	
	
	
	for(int i=0;i<9;i++){
		box=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr[k][i])-1]=1;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==0){
				box=k+1;
				break;
			}
		}
			
		
		arr[8][i]=box;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=0;
		}
		
		
		
				
	}
	

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	

	return 0; 
}
