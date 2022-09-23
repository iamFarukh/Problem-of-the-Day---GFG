//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> res;
        deque<int> q;

        int i = 0;
        for (i = 0; i < k; i++) {

            while ((!q.empty()) && (arr[i] >= arr[q.back()])) q.pop_back();

            q.push_back(i);
        }

        for (; i < n; i++) {

            res.push_back(arr[q.front()]);

            while ((!q.empty()) && (q.front() <= i - k)) q.pop_front();

            while ((!q.empty()) && (arr[i] >= arr[q.back()])) q.pop_back();

            q.push_back(i);
        }

        res.push_back(arr[q.front()]);
        q.pop_front();

        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
