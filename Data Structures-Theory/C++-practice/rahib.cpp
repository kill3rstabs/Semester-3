#include<iostream>
using namespace std;
int main()
{
	int count1=0,count0=0;
   int rows,colums;
   cout<<"enter the rows of matrix"<<endl;
   cin>>rows;
   cout<<"enter the colum of matrix"<<endl;
   cin>>colums;
   
  int matrix[rows][colums];
  
  if(rows==colums)// checking for square matrix(rows==colums)

{
	cout<<"the given matrix is square matrix"<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<colums;j++)
		{
			cout<<"enter values of row"<< i << " " <<"And colums"<<j <<" "<<endl;
			cin>>matrix[i][j];
		}
	}
}
else
{
	cout<<"your given matrix isnt square matrix."<<endl;
}
     // for checking the identical matrix.
      bool flag=false;
     for(int i=0;i<rows;i++)
     {
     	for(int j=0;j<colums;j++)
     	{
     		if((i==j) && matrix[i][j]==1);
     		{
			
     		count1 +=1;
     		
     	}
     	if((i!=j) && matrix[i][j]==0)
     	{
     		count0 +=1;
     		
		 }
		 	 
	 }

}

    if(count1 == rows && count0 ==count1 *(rows-1))
		cout<<"given matrix is identical."<<endl;
	else
		cout<<"not identical."<<endl;
}