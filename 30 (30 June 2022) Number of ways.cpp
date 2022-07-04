long long int arrangeTiles(int N){
        // code here
        vector< long long int > DP(N+1,1);
        for( long long int i = 4;i<=N;i++){
            DP[i] = DP[i-1] + DP[i-4];
        }
        return DP[N];
    }
