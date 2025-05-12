#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<string> &board,int row,int col,int n)
{
    int duprow = row;
    int dupcol= col;

   //top left attack
   while(row>=0 && col>=0)
   {
    if(board[row][col]=='Q')
    {
        return false;
    }
    row--;
    col--;
   }

   //left attack
   row = duprow;
   col = dupcol;

   while(col>=0)
   {
    if(board[row][col]=='Q')
    {
        return false;
    }
    col--;
   }

    //left down attack
   row = duprow;
   col = dupcol;

   while(row<n && col>=0)
   {
    if(board[row][col]=='Q')
    {
        return false;
    }
    row++;
    col--;
   }

return true;
}
void solve(vector<string> &board,vector<vector<string>> &ans,int n,int col)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0;row<n;row++)
    {
        if(isSafe(board,row,col,n)==true)
        {
            board[row][col]='Q';
            solve(board,ans,n,col+1);
            board[row][col] ='.';
        }
    }

}
int main()
{
    int n = 4;
    vector<string> board;
    string temp(4,'.');
    for(int i = 0;i<n;i++)
    {
        board.push_back(temp);
    }

    vector<vector<string>> ans;

    solve(board,ans,n,0);

    for(int i = 0;i<ans.size();i++)
    {
        for(int row = 0;row<n;row++)
        {
           cout<<ans[i][row];
           cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }

}