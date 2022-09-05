//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    int n= nums.size();
	    vector<int> ans;
	    int possible[10000+4];
	    memset(possible, 0, sizeof(possible));
	    possible[0] = 1;
	    ans.push_back(0);
	    vector<int> cur;// finding all the possible from a particular array element


	    for(int i=0;i<n;i++){
	        for(int j =0; j<=1e4;j++){
	            if(possible[j]){
	                cur.push_back(j+nums[i]);// pushing all the possible answers in cur array 
	            }
	        }
	        // following step is to check that whether we have already included that element as our answer or not already
	        for(int k =0;k<cur.size();k++){
	            if(!possible[cur[k]]){
	                possible[cur[k]]= 1;
	                ans.push_back(cur[k]);
	            }
	        }
	        cur.clear();
	    }
	    sort(ans.begin(), ans.end());
	    // the above thing is done because we want the answer in the sorted format and since we are pushing elements as not necessarily in increasing order
	    
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends
