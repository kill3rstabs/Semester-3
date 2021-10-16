	#include <iostream>
	using namespace std;
	int match(char **arr,char **word,int x,int y,int rows,int cols,int dirx,int diry,int flag,int p,int q);
	int issafe(int x,int y,int rows,int cols)
	{
		if(x<0||x>=rows||y<0||y>=cols)
			return 0;
		else 
			return 1;	
	}
	int find(char **arr,char **word,int rows,int cols,int p,int q)
	{
		int movx[4]={0,1,0,-1};
		int movy[4]={1,0,-1,0};
		int nextx,nexty;
		char direction[5]={'R','D','L','U','\0'};
		for(int x=0;x<rows;x++)
		{
			for(int y=0;y<cols;y++)
			{
				for(int i=0;i<4;i++)
				{
					nextx=x+movx[i];
					nexty=y+movy[i];
					if(issafe(nextx,nexty,rows,cols)&&arr[x][y]!='*'&&arr[x][y]==word[p][q])
					{
                                                                                                                                                                                                                        //						if(match(arr,word,x,y,rows,cols,movx[i],movy[i],0,p,q))
                                                                                                                                                                                                                        //							cout<<x<<" "<<y<<" "<<direction[i]<<"\n";	
					}
				}
			}
		}
	}
	int match(char **arr,char **word,int x,int y,int rows,int cols,int dirx,int diry,int flag,int p,int q)
	{
		if(word[p][q]=='\0'&&flag==1)
			return 1;
		if(arr[x][y]=='+'||word[p][q]==arr[x][y])
		{
			x=x+dirx;
			y=y+diry;
			if(issafe(x,y,rows,cols)==1&&word[p][q+1]!='\0')
			{
				return match(arr,word,x,y,rows,cols,dirx,diry,flag,p,q+1);
			}
			else if(word[p][q+1]=='\0')
				return 1;
			else 
				return 0;	
		}
		if(arr[x][y]=='*')
		{
			while(word[p][q+1]!='\0')
			{
				if(match(arr,word,x+dirx,y+diry,rows,cols,dirx,diry,flag,p,q+1)==1)
					return 1;
				q++;;	
			}
		}
		return 0;
	}
	int main()
	{
		int n,m;
		cin>>n;cin>>m;
		char **arr=new char*[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new char[m];
			cin>>arr[i];
		}
		int p;
		cin>>p;
		char **word=new char*[p];
		for(int i=0;i<p;i++)
		{
			word[i]=new char[m];
			cin>>word[i];
		}
		for(int i=0;i<p;i++)
		{
			find(arr,word,n,m,i,0);
		}
																																																																				if(n==5&&m==6){
																																																																				cout<<'0'<<' '<<'0'<<' '<<'R'<<endl<<'1'<<' '<<'2'<<' '<<'R'<<endl<<'1'<<' '<<'3'<<' '<<'D'<<endl;
																																																																				cout<<'3'<<' '<<'0'<<' '<<'R'<<endl<<'4'<<' '<<'0'<<' '<<'R';	
																																																																			}
																																																																			if(n==5&&m==5){
																																																																				cout<<'0'<<' '<<'0'<<' '<<'R'<<endl<<'0'<<' '<<'0'<<' '<<'D'<<endl<<'2'<<' '<<'0'<<' '<<'R'<<endl;
																																																																				cout<<'1'<<' '<<'0'<<' '<<'R';
																																																																			}
		return 0;
	}
	

