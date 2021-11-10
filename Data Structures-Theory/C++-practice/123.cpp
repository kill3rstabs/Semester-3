	int num,mod,divide;
	int reverse = 0;
	printf("Input five digit integer\n:");
	scanf("%d",&num);
	if(num<100000)
	{
		mod = num % 10;
		reverse=reverse+mod;
		divide=num/10;
		
		mod= divide  %  10;
		reverse=  reverse * 10 + mod;
		divide=divide/10;
		
		mod=divide%  10;
		reverse= reverse * 10 +  mod;
		divide=divide/10;
		
		
		mod=divide %  10;
		reverse  =  reverse *  10 + mod;
		divide   =  divide/10;
		
		mod=divide %  10;
		reverse   =  reverse * 10 + mod;
		divide = divide/10;
		
		
		if(num==reverse){
			printf("it is a palindrome");
		}		
		else {
			printf("it is not a palindrome");
		}
		
	}
		else
		{printf("Error!Please enter a five digit integer ");
		} 
	
		
		return 0;
	}
	
