//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int MinimumExchange(vector<vector<char>>&mat) {
        int n = mat.size();
        int m = mat[0].size();
        int a = 0 , b = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (mat[i][j] == 'A') {
                    a++;
                } else {
                    b++;
                }
            }
        }
        auto helper = [&] (char x, char y) {
            int cnt = 0;
            for (int i = 0 ; i < n;  i++) {
                for (int j = 0 ; j < m; j++) {
                    if (i % 2 == j % 2) {
                        if (mat[i][j] == x) {
                            cnt++;
                        }
                    } else {
                        if (mat[i][j] == y) {
                            cnt++;
                        }
                    }
                }
            }
            return cnt / 2;
        };
        int x=INT_MAX;
        if ((((n * m) & 1) && a > b) || ((n * m) % 2 == 0)) {
            x = helper('B', 'A');
        }
        if ((((n * m) & 1) && b > a) || ((n * m) % 2 == 0)) {
            x = min(x, helper('A', 'B'));
        }
        return x;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
