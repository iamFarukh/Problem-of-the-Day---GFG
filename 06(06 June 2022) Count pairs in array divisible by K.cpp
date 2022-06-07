long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<int,int> m;
        long ans = 0;
        for(int i = 0;i<n;i++){
            int rem1 = A[i]%K;
            if(rem1 != 0)
            ans += m[K-A[i]%K];
            else{
                ans += m[0];
            }
            m[rem1]++;
        }
        return ans;
    }
