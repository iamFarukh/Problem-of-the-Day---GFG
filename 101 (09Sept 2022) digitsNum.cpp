//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int N)
	{
	    string ans;
	    int curr_num;
	    stack<int> s;
	    int init_num = N;
	    if(N<=9) {
	        ans += char(N + '0');
	        for(int i=0;i<N;i++) {
	            ans+="0";
	        }
	    }
	    else {
	        while(N>=10) {
	            s.push(9);
	            N-=9;
	        }
	        s.push(N);
	        while(!s.empty()) {
	            ans+=char(s.top()+'0');
	            s.pop();
	        }
	        for(int i=0;i<init_num;++i) {
	            ans += "0";
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
