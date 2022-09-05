//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int mod=1e9+7;
    long long solve(string &str,int i,int j,vector<vector<long long>> &dp){
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str[i]==str[j])
            return dp[i][j]=(1+solve(str,i+1,j,dp)+solve(str,i,j-1,dp))%mod;//if the given string is palindrome then ans is 1+ solve(excluding last char)+solve(excluding first char)
        
        else
            return dp[i][j]=(mod+solve(str,i+1,j,dp)+solve(str,i,j-1,dp)-solve(str,i+1,j-1,dp))%mod;//else exclude first char+exclude last char-exclude first and last char
        
    }
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       vector<vector<long long>> dp(1001,vector<long long>(1001,-1));//memoization
       return solve(str,0,str.size()-1,dp);
       
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
