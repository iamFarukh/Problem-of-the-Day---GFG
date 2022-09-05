//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	   // arr[n] = -1;
	   // for(int i=0;i<n;i++){
	   int i =0;
	   while(i<n){
	        for(int j=i+1;j<n;j++){
	            if(arr[i]>arr[j]){
	                arr[i] = arr[j];
	                break;
	            }
	            else{
	                arr[i] = -1;
	                break;
	            }
	        }
	        i++;
	}
	arr[n-1] = -1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
