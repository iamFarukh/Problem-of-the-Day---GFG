//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(), X.end(), greater<int>());
        sort(Y.begin(), Y.end(), greater<int>());
        int totalCost = 0;
        int horizontalComponent = 1;
        int verticalComponent = 1;
        int i = 0;
        int j = 0;
        while(i < M - 1 && j < N - 1){
            if(X[i] >= Y[j]){
                totalCost += X[i]*horizontalComponent;
                verticalComponent++;
                i++;
            }
            else{
                totalCost += Y[j]*verticalComponent;
                horizontalComponent++;
                j++;
            }
        }
        while(i < M - 1){
            totalCost += X[i]*horizontalComponent;
            verticalComponent++;
            i++;
        }
        while(j < N - 1){
            totalCost += Y[j]*verticalComponent;
            horizontalComponent++;
            j++;
        }
        return totalCost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
