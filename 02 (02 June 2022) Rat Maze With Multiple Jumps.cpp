vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   vector<vector<int>>ans(matrix.size(),vector<int>(matrix[0].size(),0));
	   if(!ratmaze(matrix,ans,0,0))
	   return {{-1}};
	   return ans;
	}
	
	bool withinboundary(int i,int j,vector<vector<int>>&matrix)
	{
	    if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==0)
	    return false;
	    
	    return true;
	    
	}
	
	bool ratmaze(vector<vector<int>>&matrix,vector<vector<int>>&ans,int i,int j)
	{   
	    if(i==matrix.size()-1 && j==matrix[0].size()-1)
	    { ans[i][j]=1;
	    return true;
	    }
	    if(withinboundary(i,j,matrix))
	    {   ans[i][j]=1;
	        
	        for(int noofsteps=1;noofsteps<=matrix[i][j];noofsteps++)
	        {
	            if(ratmaze(matrix,ans,i,j+noofsteps))return true; //right
	            if(ratmaze(matrix,ans,i+noofsteps,j))return true; //down
	            
	        }
	        
	        ans[i][j]=0;
	    }
	    
	    return false;
	    
	}
