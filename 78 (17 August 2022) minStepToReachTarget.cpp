//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int dx[8]={2,2,1,-1,-2,-2,1,-1};
int dy[8]={1,-1,2,2,1,-1,-2,-2};
bool valid(int x, int y, int n, vector<vector<bool>>&vis)
{
    if(x<0 || y<0 || x>=n || y>=n || vis[x][y]==true)
    return false;
    return true;
}
int minStepToReachTarget(vector<int>&kp, vector<int>&tp, int N){
     vector<vector<bool>>vis(N,vector<bool>(N,false));
    int ans=0;
    queue<pair<int, int>>qu;
    qu.push({kp[0]-1, kp[1]-1});
    vis[kp[0]-1][kp[1]-1]=true;
    while(!qu.empty())
    {
        int n=qu.size();
        for(int i=0; i<n; i++)
        {
            pair<int, int> t=qu.front();
            qu.pop();
            int p=t.first;
            int q=t.second;
            if(p==tp[0]-1 && q==tp[1]-1)
            return ans;
            for(int j=0; j<8; j++)
            {
                if(valid(p+dx[j], q+dy[j], N, vis))
                {
                    qu.push({p+dx[j], q+dy[j]});
                    vis[p+dx[j]][q+dy[j]]=true;
                }
            }
            
        }
        ans++;
    }
    return -1;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
