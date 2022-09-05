//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   String findSum(String x, String y) {       
      
		int rem=0;
		int i=x.length()-1;
		int j=y.length()-1;
		String ans="";
		while(i>=0 && j>=0) {
			int a=x.charAt(i)-'0';
			int b=y.charAt(j)-'0';
			int z=a+b+rem;
			rem=z/10;
			z=z%10;
			ans=z+ans;
			i--;
			j--;
		}		
		
		while(i>=0) {
			int a=x.charAt(i)-'0';
			int z=a+rem;
			rem=z/10;
			z=z%10;
			ans=z+ans;
			i--;			
		}		
		
		while(j>=0) {
			int a=y.charAt(j)-'0';
			int z=a+rem;
			rem=z/10;
			z=z%10;
			ans=z+ans;
			j--;			
		}
		if(rem!=0)ans=rem+ans;	
		
		boolean flag=false;
		for(int k=0;k<ans.length();k++){
		    if(ans.charAt(k)!='0' && flag==false ){		       
		      i=k;
		    	flag=true;
		    }
		}
		
		if(i!=-1) return (ans.substring(i));
		else return "0";		 
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends
