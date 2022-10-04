//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int sumOfAll(int l, int  r){
        vector<int> seive(r+1,0);
        seive[1]=1;
        int ans = 0;
        if(l==1) ++ans;
        for(int i=2;i<=r;i++){
            if(seive[i]==0){
                seive[i]=i;
                for(int j=i+i;j<=r;j=j+i){
                    seive[j]+=i;
                }
            }
            if(i>=l && i<=r)
                ans += seive[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends
