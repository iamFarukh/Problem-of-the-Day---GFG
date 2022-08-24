//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string low="";
        string up="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='a' && str[i]<='z')
            low+=str[i];
            else
            up+=str[i];
        }
        sort(low.begin(),low.end());
        sort(up.begin(),up.end());
        int l=0;
        int h=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='a' && str[i]<='z')
             str[i]=low[l++];
            else
             str[i]=up[h++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
