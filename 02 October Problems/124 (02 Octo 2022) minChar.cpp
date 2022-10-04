//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string s){
        //Write your code here
        int i = 0,j = s.length()-1;
        int ans = 0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                ans = s.length()-j;
                i = 0;
                while(s[i]==s[j]){
                    ans--; i++;
                }
                j--;
            }
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
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
