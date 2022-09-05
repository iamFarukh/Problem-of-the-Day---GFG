//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> pattern(int n){
        // code here
        int x=1;
       int y=n*n+1;
       vector<string> str(n);
       
       for(int i=0;i<n;i++){
           string s="";
           for(int j=0;j<i;j++){
               s=s+"--";
           }
           for(int k=0;k<n-i;k++){
               if(k!=0) s=s+"*";
               
              s=s+to_string(x);
               x++;
           }
           int a=y;
           for(int z=0;z<n-i;z++){
                s=s+"*";
                s=s+to_string(a);
               a++;
           }
           y=y-(n-(i+1));
           str[i]=s;
       }
       return str;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
// } Driver Code Ends
