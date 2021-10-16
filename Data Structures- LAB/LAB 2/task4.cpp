#include<iostream>
#include <stdlib.h>	
using namespace std;
int main(){
	bool friends[5][5]={{false,true,false,true,true},
	{true,false,true,false,true},
	{false,true,false,false,false},
	{true,false,false,false,true},
	{true,true,false,true,false},
	};
	int count[5]={0,0,0,0,0};
	int m=1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(friends[i][j]==true){
				count[j]=1;
				m++;
			}
		}
		if(m>2){
			cout<<"Common friends of "<<i<<" are ";
			for(int k=0;k<5;k++){
				if(count[k]==1)
				cout<<k<<",";
			}
			cout<<endl;
		}
		memset(count,0,sizeof(count));
		m=1;
	}
	
}