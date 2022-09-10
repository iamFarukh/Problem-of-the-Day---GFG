//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &a,vector<int> &b){
        queue<int>q1;
        queue<int>q2;
        stack<int>stk;
        for(auto i:a)
            q1.push(i);
            
        for(auto i:b)
            q2.push(i);
            
        while(!q1.empty()){
            int t=q1.front();
            q1.pop();
            if(t==q2.front()){
                q2.pop();
                
                
                while(!stk.empty()){
                    if(stk.top()==q2.front()){
                        stk.pop();
                        q2.pop();
                    }
                    else
                        break;
                }
            }
            else
                stk.push(t);
        }
        
        if(q1.empty()&&stk.empty())
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
