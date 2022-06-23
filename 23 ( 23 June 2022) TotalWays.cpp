class Solution{
	 long long mod = 1000000007;
	long long dp[100001][2];
	long long solve(int plots, int i, bool prev){
	    if(i == plots) return 1;
	    if(dp[i][prev] != -1) return dp[i][prev];
	    int take = 0, donttake = 0;
	    if(!prev) take = solve(plots, i+1, true);
	    donttake = solve(plots, i+1, false);
	    return dp[i][prev] =  (take + donttake) % mod;
	}
	
	public:
	int TotalWays(int N)
	{
	    memset(dp, -1, sizeof(dp));
	    long long ans = solve(N, 0, 0);
	    ans = (ans * ans) % mod;
	    return (int)ans;
	}
};
