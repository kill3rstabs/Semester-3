#include<stdio.h>

int main()
{
    int num,mod,rev;
    int Entered_num;
    
    printf("Enter a five digit number to check pelindrome\nNumber:");
    scanf("%d",&num);
	Entered_num=num;

	  while (num != 0)
   {	
        mod = num % 10;				// Here we are reversing number
        rev = rev * 10 + mod;		// to check pelindrome
        num /= 10;
     
}
	printf("\nReversed number = %d\n",rev);
               
	
	if(Entered_num==rev)
	{
		printf("\nThe number %d is a pelindrome",Entered_num);
	}
	else
	{
		printf("\nThe number %d is not a pelindrome",Entered_num);
	}}
