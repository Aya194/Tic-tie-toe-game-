#include <iostream>
using namespace std;

int main() {
    char grid[100][100] ; //grid haas three values . for empty, x , o
    int n;
    cout<<"please enter the grid size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            grid[i][j]='.';
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    //to move in each row,col or diagonal we need starting point and direction
    int dir_row[100],dir_col[100],start_row[100],start_col[100];
    int verify=0;

    //the start point for any row is (r,0) r=0,1,2,3..n
    //the start point for any col is (0,c) c=0,1,2,3,4..n


    //add row n positions to verify (getting the start points and fillig the dirctions)
    for(int r=0;r<n;r++)
    {
        start_row[verify]=r;
        start_col[verify]=0;
        dir_row[verify]=0;
        dir_col[verify]=1;
        verify++;
    }
    //to move one step in col the direction is(1,0)
    //add column n positions
    for(int c=0;c<n;c++)
    {
        start_row[verify]=0;
        start_col[verify]=c;
        dir_row[verify]=1;
        dir_col[verify]=0;
        verify++;
    }

    //the start for left diagonal always from(0,0)
    start_row[verify]=0; start_col[verify]=0; dir_row[verify]=1; dir_col[verify]=1;
    verify++;
    //the start for right diagonal always from(0,n-1)
    start_row[verify]=0; start_col[verify]=n-1; dir_row[verify]=1; dir_col[verify]=-1;
    verify++;

    int turn=0 ; //turn has two values 0 for x, 1 for o
    int steps=0;
    while(true) //keep looping until win or tie
    {
        if(steps==n*n) //moved along the complete grid
        {
            cout<<"the game ended with tie";
            break;
        }

        //get the positin from user
        if(turn==0)
            cout<<"player X please enter the desired position "<<endl;
        else
            cout<<"player O please enter the desired position "<<endl;
        int r,c ;
        cin>>r>>c;
        r--,c--;

        //check position valid or not
        if(r>=n||r<0||c>=n||c<0||grid[r][c]!='.')
        {
            cout<<"invalid choice please enter another position"<<endl;
            continue;
        }

        if (turn==0)
            grid[r][c]='X';
        else
            grid[r][c]='O';

        //print the updated grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        //check win checks=2n+2
        for(int check=0;check<verify;check++) //get the start point for each check
        {
          int sr = start_row[check] , sc=start_col[check],dr=dir_row[check],dc=dir_col[check];
          int cnt=0; char first_element=grid[sr][sc];
          if(first_element=='.')
              continue;
          for(int i=0;i<n;i++,sr+=dr,sc+=dc) //iterate over given row or col or diagonal (moving along each index with the help of dir array)
          {
              cnt+=grid[sr][sc]==first_element;
          }
          if(cnt==n&&turn==0)
          { cout<<"***PLAYER X IS THE WINNER!!***"<<endl;
              return 0;
          }
          else if(cnt==n&&turn==1)
            { cout<<"***PLAYER O IS THE WINNER!!**"<<endl;
                return 0;
            }
        }
        steps++;
        turn=!turn; //flip player
    }

    return 0;
}