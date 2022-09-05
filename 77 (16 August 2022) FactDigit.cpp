//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> FactDigit(int N)
{
    vector<int>v={1,1,2,6,24,120,720,5040,40320,362880};
    int i=9;
    vector<int>ans;
    while(N>0)
    {
        while(v[i]>N)
        {
            i--;
        }
        ans.push_back(i);
        N=N-v[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
