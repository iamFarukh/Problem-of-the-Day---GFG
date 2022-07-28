//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        int count = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i =0;i<n;i++) pq.push(arr[i]);
        
        if(pq.top() >=k){
            return 0;
        }
        
        while(true){
            int first = pq.top();pq.pop();
            
            int second = pq.top();pq.pop();
            pq.push(first+second);
            count++;
            
            if(pq.top() >=k) break;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
