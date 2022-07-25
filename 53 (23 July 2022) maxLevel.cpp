//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int maxLevel(int h,int m)
        {
            // code here
            int level = 0;
        bool level1 = true;
          while(h>0 && m>0){
              if(level1){
                  h+= 3;m+=2;
                  level++;
                  level1 = false;
              }
              else{
                  level++;
                  level1 = true;
                  if(h>5 && m>10){
                  h-=5;m-=10;
                  }
                  else{
                  h-=20;m+=5;
                  }
                 }
          }
          return level-1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
