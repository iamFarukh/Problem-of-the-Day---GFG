//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
    	string str = "";
    	string ans = "";
    	int cut = 0;
    	int n = S.length();
    	
    	for(int i = 0; i < n; i++){
    	    if(S[i] == '-') continue;
    	    else if(S[i] >= '0' && S[i] <= '9') str += S[i];
    	    else str += toupper(S[i]);
    	}
    	
    	for(int i = str.length() - 1; i >= 0; i--){
    	    ans += str[i];
    	    cut++;
    	    if(cut == K){
    	        ans += '-';
    	        cut = 0;
    	    }
    	}
    	
    	reverse(ans.begin(), ans.end());
    	
    	if(ans[0] == '-') return ans.substr(1);
    	
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
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends
