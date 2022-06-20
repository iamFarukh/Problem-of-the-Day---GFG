class Solution {
public:
   vector<int> p={0,1,0,-1,0};
   int func(vector<vector<int>> &mat,int i,int j,int xd,int yd){
       if(i==xd and j==yd) return 0;
       int b=mat[i][j];
       mat[i][j]=0;
       int m=INT_MIN;
       for(int k=0;k<4;k++){
           int x=i+p[k],y=j+p[k+1];
           if(x<0 or y<0 or x==mat.size() or y==mat[0].size() or !mat[x][y]) continue;
           int a=func(mat,x,y,xd,yd);
           if(a!=INT_MIN) m=max(m,1+a);
       }
       mat[i][j]=b;
       return m;
   }
   int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
   {
       // code here
       if(!matrix[xs][ys]) return -1;
       int b=func(matrix,xs,ys,xd,yd);
       if(b==INT_MIN) return -1;
       return b;
   }
};
