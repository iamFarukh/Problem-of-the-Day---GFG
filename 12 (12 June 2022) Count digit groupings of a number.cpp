class Solution{
	int n;
    int presum[105] = {0};
	public:
	int rec(int ind, int prev, string s, vector<vector<int>>& dp){
	    if(ind == n)    return 1;
	    if(dp[ind][prev] != -1)     return dp[ind][prev];
	    
	    int res = 0;
	    for(int i=ind; i<n;i++){
	        int sum = presum[i+1] - presum[ind];
	        if(sum >= prev)     res += rec(i+1, sum, s, dp);
	    }
	    return dp[ind][prev] = res;
	}
	
	int TotalCount(string str){
	    // Code here
	    n = str.length();
	    for(int i=1;i<=n;i++)    presum[i] = presum[i-1] + (str[i-1]-'0');
	    
	    vector<vector<int>> dp(n, vector<int>(1000, -1));
	    return rec(0, str[0]-'0', str, dp);
	}

};
