#include <stdio.h>

int main(){
	//declaring variables 
	int num1,num2,num3,sq1,sq2,sq3,cube1,cube2,cube3;
	
	//taking inputs
	printf("\nEnter num 1: ");
	scanf("%d",&num1);
	
	printf("\nEnter num 2: ");
	scanf("%d",&num2);
	
	printf("\nEnter num 3: ");
	scanf("%d",&num3);
	
	//calculation of suqare and cubes
	sq1 = num1*num1;
	sq2 = num2*num2;
	sq3 = num3*num3;
	cube1 = sq1* num1;
	cube2 = sq2* num2;
	cube3 = sq3* num3;
	
	printf("\nThe square of num1 is %d:",sq1);
	printf("\nThe square of num1 is %d:",cube1);
	
	
	printf("\nThe square of num2 is %d:",sq2);
	printf("\nThe square of num2 is %d:",cube2);
	
	
	printf("\nThe square of num3 is %d:",sq3);
	printf("\nThe square of num3 is %d:",cube3);
	
	
	
}
