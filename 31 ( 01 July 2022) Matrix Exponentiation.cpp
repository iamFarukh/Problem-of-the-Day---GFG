public:
    int mod = 1e9 + 7;
    
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b){
        vector<vector<long long>> arr(2, vector<long long>(2,0));
        arr[0][0] = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod;
        arr[0][1] = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod;
        arr[1][0] = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod;
        arr[1][1] = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod;
        return arr;
    }
    
    vector<vector<long long>> exponentiate(vector<vector<long long>> &m, long long n){
        auto ans = m;
        while(n > 0){
            if(n & 1){
                ans = multiply(ans,m);                
            }   
            m = multiply(m,m);
            n = n >> 1;
        }
        return ans;
    }
    
    int FindNthTerm(long long int n) {
        vector<vector<long long>> a = {{1,1}, {1,0}};
        if(n == 0) return 0;
        if(n == 1) return 1;
        auto ans = exponentiate(a, n - 1);
        return ans[0][0];
    }
