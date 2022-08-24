//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector <vector <int>> dp;
    int helper(vector<int>&A, int i, int j)
    {
        if (i == j)
            return A[i];
        if (i + 1 == j)
            return max(A[i], A[j]);
        if (dp[i][j] == 0)
        {
            int start = A[i] + min(helper(A, i + 2, j), helper(A, i + 1, j - 1));
            int end = A[j] + min(helper(A, i + 1, j - 1), helper(A, i, j - 2));
            dp[i][j] = max(start, end);
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>&A,int n) {
	    //Write your code here
	    dp = vector <vector <int>> (n + 1, vector <int> (n + 1, 0));
	    return helper(A, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

// } Driver Code Ends
