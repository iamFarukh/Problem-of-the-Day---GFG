//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		 bool prime(int p){
            for(int i=2;i<=sqrt(p);i++){
                if(p%i==0)
                    return 0;
            }
             
            return 1;
         }
     int Count(int L, int R){
        int p=0,c=0;
        if(L==1)
           L++;
        for(int i=L;i<=R;i++){
            if(prime(i))
                 p++;
            else
              c++;
        }
        return c-p;
    
     }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
