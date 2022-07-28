//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long mod = 1000000007;
    long long combi(int n, int r){
        if(n - r < r){
            r = n - r;
        }
        long long dp[n + 1][r + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
            }
        }
        return dp[n][r];
    }
    
    int knots(int M, int N, int K){
		return (combi(M, K) % mod * combi(N, K) % mod)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int M, N, K;
        cin>>M>>N>>K;
        
        Solution ob;
        cout<<ob.knots(M, N, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
