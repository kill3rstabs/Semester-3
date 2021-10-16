#include<stdio.h>
int main(){
	float x,y;
	float z; 
	int ans;
	
	z = x%y;
	ans = (int) z;
	
	printf("Enter x:");
	scanf("%d",&x);
	printf("Enter y:");
	scanf("%d",&y);
	
	
	
	printf("\nThe sum of x and y is = %.2f", x+y);
	printf("\nThe sub of x and y is = %.2f", x-y);
	printf("\nThe product of x and y is = %.2f", x*y);
	printf("\nThe divsion of x and y is = %.2f", x/y);
	printf("\nThe mod of x and y is = %d", z);
	printf("\nThe increment of x is = %.2f", ++x);
	printf("\nThe increment of y is = %.2f", ++y);
	
	x=--x;
	y=--y;
	
	printf("\nThe decrement of x is = %d", --x);
	printf("\nThe decrement of y is = %d", --y);
}
