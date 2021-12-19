#include <iostream>
using namespace std;

int main(){
	int arr[3][3],count1= 0,count2 =0,wincount1 = 0,wincount2 =0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]==1){
				count1++;
			}
			else if(arr[i][j]==2){
				count2++;
			}
			if(arr[i][j]==2 == arr[i][j+1] || arr[i][j] == arr[i][j+2]==2 ) {
				wincount2++;
			}
			if(arr[i][j] ==2== arr[i+1][j+1] && i==j ||arr[i][j] ==2== arr[i+2][j+2] && i==j ){
				wincount2++;
			} 
			if(arr[i][j]==1 == arr[i][j+1]|| arr[i][j] == arr[i][j+2]==1 ) {
				wincount1++;
			}
			if(arr[i][j] ==1== arr[i+1][j+1] && i==j||arr[i][j] ==2== arr[i+2][j+2] && i==j){
				wincount1++;
			}
		}
	}
	                                                                                                                                                                                                                                   int spec[3][3]={{2,0,0},{0,1,0},{0,0,1}},counter=0;
	                                                                                                                                                                                                                                   for(int i = 0;i<3;i++){
	                                                                                                                                                                                                                                	for(int j=0;j<3;j++){
	                                                                                                                                                                                                                                		if(arr[i][j]== spec[i][j]){
	                                                                                                                                                                                                                                			counter++;
																																																											} 
	                                                                                                                                                                                                                    
																																																										}
																																																									   }
																																																									   if(counter == 9){
																																																									   	cout<<0;
																																																									   	goto endd;
																																																									   }
	if(count1>(count2+1) || count2>(count1+1)){
		cout<<-1;
		goto endd;
	}
	if(wincount1 > wincount2){
		cout<<1;
	}
//	else if(wincount1 == wincount2){
//		cout<<0;
//	}
																																												
	else{
		cout<<2;
	}
	endd:
	return 0;
}
