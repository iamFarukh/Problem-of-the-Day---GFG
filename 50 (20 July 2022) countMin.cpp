//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int helper(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return dp[i][j] = 0;
        }
        if (i == j)
        {
            return dp[i][j] = 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == s[j])
        {
            if (dp[i + 1][j - 1] == -1)
            {
                dp[i + 1][j - 1] = helper(s, i + 1, j - 1, dp);
            }
            return dp[i][j] = 2 + dp[i + 1][j - 1];
        }
        else
        {
            if (dp[i + 1][j] == -1)
            {
                dp[i + 1][j] = helper(s, i + 1, j, dp);
            }
            if (dp[i][j - 1] == -1)
            {
                dp[i][j - 1] = helper(s, i, j - 1, dp);
            }
            return dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    int countMin(string str)
    {
        int n = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return n - helper(str, 0, n - 1, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
