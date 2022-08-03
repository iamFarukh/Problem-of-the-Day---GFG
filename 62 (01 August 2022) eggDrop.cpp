//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
   int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                
                if(i == 1)
                    dp[i][j] = j;
                
                else if(j == 1)
                    dp[i][j] = 1;
                else {
                int ans = INT_MAX;
                for(int pi = 0, ci = j-1; ci >= 0; ci--,pi++) {
                    ans = min(ans,max(dp[i][ci],dp[i-1][pi]));
                }
                dp[i][j] = ans+1;
                }
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
