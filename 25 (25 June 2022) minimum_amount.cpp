long long Total = 1e18;
    bool overDemand = false;
    long long water(vector<int> adj[], int *Cap, int visited[], int source)
    {
        visited[source] = 1;
        long long ans = 0;
        int count = 0;
        for (auto x : adj[source])
        {
            if (visited[x]==0)
            {
                count++;
                long long temp = water(adj, Cap, visited, x);
                ans = max(temp, ans);
            }
        }
        long long waterReq = count * ans + Cap[source-1];
        if(waterReq>Total) overDemand = true;
        return waterReq;
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap)
    {
        // Code here
        int visited[N + 1] = {0};
        vector<int> adj[N+1];
        for(int i=0;i<Edges.size();i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        long long  ans = water(adj, Cap, visited, S);
        return overDemand==true ? -1 : ans;
    }
