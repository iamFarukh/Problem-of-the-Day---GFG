//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isprime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3)  return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
    }
    int no_of_senior(int i,vector<int>&arr,vector<int>&dp)
    {
        if(arr[i]==0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = 1+no_of_senior(arr[i]-1,arr,dp);
    }
    int firingEmployees(vector<int> &arr, int n){
        // code here 
        vector<int>dp(n,-1);
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1) dp[i] = no_of_senior(i,arr,dp);
            if(dp[i]!=0 && isprime(i+1+dp[i])) count++;
        }
     return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
