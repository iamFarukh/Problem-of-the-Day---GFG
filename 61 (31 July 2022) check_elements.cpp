//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	 bool check_elements(int arr[], int n, int A, int B)
    {
        if(n==1)
        return 0;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int sum=0;
     for(int i=A;i<=B;i++)
     sum+=i;
     for(auto x:s){
         if(x>=A && x<=B)
         sum-=x;
     }
     return (sum==0);
    }


		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends
