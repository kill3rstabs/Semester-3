#include <iostream>

using namespace std;
//part 1
// void rec(int arr[4][4], int n,int i,int moves)
// {
//     if(n==0)
//     {
//         cout<<"The possible moves are : "<<moves;
//         abort;
//     }
//     else
//     {
//         for (int k=0; k<n; k++)
//         {
//             if (arr[k][i]==1)
//             {
//                 moves++;
//                 rec(arr, n-1, i+1, moves);
//             }
//             rec(arr, n-1, i+1, moves);
//         }

//     }
// }

// int main()
// {
//     int arr[4][4]={
//         {1,0,0,0},
//         {1,1,0,1},
//         {0,1,0,0},
//         {1,1,1,1}
//     };

//     int n=sizeof(arr)/sizeof(arr[0][0]);
//     int i=0;

//     rec(arr, n, i, 0);
//     // cout<<n;
// }


//part 2

void rec(int arr[4][4], int i, int j){
	char dec;
	cout<<"position == "<<arr[i][j];
	if(arr[i][j]==6)
    {
		cout<<"destination reacahed";
	}
	else
    {
		cout<<"F-forward B-backwards D-downwards: ";
		cin>>dec;
	
		if(dec=='f'||dec=='F')
        {
			j=j+1;
			if(arr[i][j]==0)
            {
				cout<<"canot move there";
				j=j-1;
				rec(arr,i,j);
			}	
			else
            {
				rec(arr,i,j);
			}
		}	
		
		else if(dec=='d'||dec=='D')
        {
			i=i+1;
			if(arr[i][j]==0)
            {
				cout<<"\nCANNOT MOVE THERE!!!";
				i=i-1;
				rec(arr,i,j);
			}	
			else
            {
				rec(arr,i,j);
			}
		}

        else if(dec=='B'||dec=='b')
        {
            j--;
			if(arr[i][j]==0)
            {
				cout<<"\nCANNOT MOVE THERE!!!";
				j++;
				rec(arr,i,j);
			}	
			else
            {
				rec(arr,i,j);
			}   
        }
		
	}
}

int main()
{
    int arr[4][4]={
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,6}
    };

    rec(arr, 0,0); 

}