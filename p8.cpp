//240. Search a 2D Matrix II
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(int matrix[5][5], int target,int row,int col) {
       
        int i = 0;
        int j = col-1;

        while(i<row && j>=0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                //element is not present in that column
                //eliminate the column
                j--;
            }
            else {
                //element is not present in that row
                //eliminate the row
                i++;
            }
        }

        return false;
        
    }



int main()
{
    int matrix[5][5] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    searchMatrix(matrix,10,5,5) ? cout<<"Elemenbt found"<<endl : cout<<"Elemenbt found"<<endl; 
}