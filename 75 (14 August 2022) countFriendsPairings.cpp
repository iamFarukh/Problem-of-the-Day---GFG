//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    long long dp[10005];
    int mod = 1000000007;
    long long pairs( int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        if (dp[n]!=-1) return dp[n];
        long long p = 1;
        long long a = p*(pairs(n-1))%mod;
        long long b = ((p*(n-1)%mod) * (p*pairs(n-2))%mod)%mod;
        return dp[n] = a+b;
    }
    long long countFriendsPairings(int n) 
    { 
        memset(dp, -1, sizeof dp);
        return pairs(n)%mod;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends
