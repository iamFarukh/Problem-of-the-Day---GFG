//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        // code here
        stack<int> st;
        int pairArray[] = {9,2,1,4,3,6,5,8,7,0};
        for(int i =0;i<n;i++){
            int key = s[i]-'0';
            if(st.empty()){
                st.push(key);
            }
            else{
                if(st.top() == pairArray[key]){
                    st.pop();
                }
                else{
                    st.push(key);
                }
            }
        }
    return st.size();
        
    }
    
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
