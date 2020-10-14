#include<iostream>
#define N 9
#define zero 0
using namespace std;

bool ismatch(int grid[N][N],int i,int j,int n)
{
    for(int k=0;k<9;k++)
    {
        if(grid[i][k]==n||grid[k][j]==n)
            return false;
    }
    int s=3;
    int is=i-i%s;
    int js=j-j%s;
    for(int l=0;l<3;l++)
    {
        for(int m=0;m<3;m++)
        {
            if(grid[l+is][m+js]==n)
                return false;
        }
    }
    return true;
}
bool solvesudoku(int grid[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        bool flag = false;
        for(j=0;j<N;j++)
        {
            if(grid[i][j] == zero)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(i==N && j==N)
        return true;
   
        for(int n=1;n<=9;n++)
        {
            if(ismatch(grid,i,j,n))
            {
                grid[i][j]=n;
            
                if(solvesudoku(grid))
                    return true;
                grid[i][j]=0;
                //return false;
            }
        }
        return false;
    
}
int main()
{
   
   int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
   };
   bool p=solvesudoku(grid);
   if(p)
   {
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               cout<<grid[i][j]<<" ";
           }
           cout<<"\n";
       }
   }
    return 0;
}
