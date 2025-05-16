void solve(vector<vector<int>>& maze,vector<string> &ans,string &temp,string &dir,vector<int> &delRow,vector<int> &delCol,int row,int col)
    {
        if(row==maze.size()-1 && col==maze[0].size()-1)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0;i<4;i++)
        {
            
            
            if(row>=0 && row<maze.size() && col>=0 && col<maze[0].size() && maze[row][col]==1)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                temp.push_back(dir[i]);
                maze[row][col] = 0;
                solve(maze,ans,temp,dir,delRow,delCol,newRow,newCol);
                temp.pop_back();
                maze[row][col] = 1;
            }
        }
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string dir =  "DLRU";
        vector<string> ans;
        string temp ="";
        
        vector<int> delRow = {1,0,0,-1};
        vector<int> delCol = {0,-1,1,0};
        
        solve(maze,ans,temp,dir,delRow,delCol,0,0);
        
        return ans;