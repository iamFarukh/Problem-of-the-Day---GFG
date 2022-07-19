vector<vector<int>>v;
    vector<int>v1;
    void f1(vector<vector<int>> &grid,int n,int m,int i,int j,vector<int>&v1)
    {
       v1.push_back(grid[i][j]);
       if(i+1<n) f1(grid,n,m,i+1,j,v1);
       if(j+1<m) f1(grid,n,m,i,j+1,v1);
       if(i==n-1 && j==m-1) v.push_back(v1);
       v1.pop_back();
    }
   vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
   {
       // code here
       f1(grid,n,m,0,0,v1);
       return v;
       
   }
