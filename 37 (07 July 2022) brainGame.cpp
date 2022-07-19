	bool isPrime(int n)
    {
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
              return false;
        }
        return true;
    }
    int primeFactors(int n)
    {
        int ans = 0;
        int num =n;
        for(int i=2; i<=num/2; i++)
        {
            while(n%i == 0)
            {
                ans++;
                n/= i;
            }
        }
        return ans;
    }
    bool brainGame(vector<int>nums) {
        int count = 0;
        for(auto x:nums)
        {
            if(!isPrime(x))
            {
                count = count ^ (primeFactors(x) - 1);
            }
        } 
        if(count == 0)
            return false;
        return true;
   }
