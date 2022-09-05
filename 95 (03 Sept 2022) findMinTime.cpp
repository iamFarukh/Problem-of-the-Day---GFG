//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findMinTime(int N, vector<int>&A, int L){
        sort(A.begin(),A.end());
        vector<int>count(L,0);
        vector<int>timer(L,0);
        int counter=0;
        while(counter<N){
            vector<int>donot(L,0);
            for(int i=0;i<L;i++){
                donot[i]=A[i]*(count[i]+1)+timer[i];
            }
            int index=min_element(donot.begin(),donot.end())-donot.begin();
            count[index]++;
            timer[index]+=count[index]*A[index];
            counter++;
        }
        return *max_element(timer.begin(),timer.end());}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends
