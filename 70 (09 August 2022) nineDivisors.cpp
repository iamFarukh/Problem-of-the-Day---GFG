//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long int nineDivisors(long long int N){
        //Code Here
        int sN = sqrt(N);
        vector<bool> prime(sN+1,true);
        for(int i=2;i<=sqrt(sN)+1;i++){
            if(prime[i])
            for(int j=i*i;j<=sN;j+=i){
                 prime[j]=0;
            }
        }
        vector<int> primes;
        for(int i=2;i<=sN;i++){
            if(prime[i])    primes.push_back(i);
        }
        
        int primesSize = primes.size();
        int ans=0;
        for(int i=0;i<primesSize;i++){
            long long notExceed  = sqrt(N)/primes[i];
            ans += (upper_bound(primes.begin(),primes.begin()+i,notExceed) - primes.begin());
        }
        for(int i=0;i<primesSize;i++){
            long long sq = primes[i]*primes[i];
            if(sq*sq*sq*sq <= N) ans++;
            else break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
