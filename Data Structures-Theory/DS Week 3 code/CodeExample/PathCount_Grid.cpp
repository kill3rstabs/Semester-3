/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion Counting Possible Paths (Examples)                    *
*          Grid (nXn) from 0,0 to n,n possible moves from right and down   * 
* Dated: October 19, 2007                                                  *
* Version: 2.0                                                             *                                                 
* Last modified: October 21, 2007                                          *
****************************************************************************/




#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>


const int n = 4;
using namespace std;

char maze[n+1][n+1];

int pathCount = 0;

// Redrawing the grid on the screen for moving
void debug()
{
     system("CLS");
     for (int i = 1; i < n+1; i++)
    {
     for (int j = 1; j < n+1; j++)
     cout << maze[j][i];
     cout << "\n";
    }
    //getch();
    Sleep(50);
}
void set()
{
    for (int i = 1; i < n+1; i++)
    {
     for (int j = 1; j < n+1; j++)
     maze[i][j] = '.';
    }
}

void countPath(int x, int y, int n)
{
     if (x == n && y == n) { pathCount += 1; //set(); 
     return; }
     if (x > n || y > n) return;
     
     maze[x][y] = 'x';
     debug();
     
     countPath(x+1,y,n);
     countPath(x,y+1,n);
     maze[x][y] = '.';
}
int main(int argc, char *argv[])
{
    set();
    maze[n][n] = 'O';
    countPath(1 ,1, n);
    cout << pathCount << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
