//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        int n=N;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=Arr[i];
        }
        sort(Arr.begin(),Arr.end());
        int cnt=0;
        long long temp=0;
        for(int i=n-1;i>=0;i--){
            temp+=Arr[i];cnt++;

            if(temp>sum-temp){
                return cnt;
            }
            
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
