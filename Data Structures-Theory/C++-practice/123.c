#include <stdio.h>
#include <math.h>
int main()
{
 int num,roll,count=0,f_digit,s_digit,t_digit,forth_digit;
 printf("ENTER YOUR ROLL NUMBER\n");
 scanf("%d",&num);
 
 if (num<=9999 || num>0000)
{
  f_digit= (int)(num/1000);
  s_digit= (int)(num%1000/100);
  t_digit= (int)(num%1000%100/10);   
  forth_digit= (int)(num%1000%100%10);  
  printf("Enter the last character of Roll number\n");
  scanf("%d",&roll);  
  if( roll==f_digit){
		count += 1;
		}
  if( roll==s_digit){
		count += 1;
		}
  if( roll==t_digit){
		count += 1;
		}
  if( roll==forth_digit){
		count += 1;
		}	
   printf("THE NUMBER OF TIME THE CHARACTER OCCUERED\n");
   printf("%d",count);
}  
   		
 else   
   printf("INVALID ROLL NUMBER "); 	
}

