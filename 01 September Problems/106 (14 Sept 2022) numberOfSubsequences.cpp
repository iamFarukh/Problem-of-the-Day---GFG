//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
        
        long long MOD = 1000000007, count = 0,ans = 1;
        
        for(int i =0; i<N; i++){
            if((A[i] & A[i]-1) ==0) count++;
        }
        
        while(count>0){
            ans = (ans*2)%MOD;
            count--;
        }
        return ans-1;
    }
    
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
