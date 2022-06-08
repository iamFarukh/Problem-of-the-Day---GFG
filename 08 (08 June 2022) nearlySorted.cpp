vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0;i<num;i++){
            if(i<K){
                pq.push(arr[i]);
            }
            else{
                pq.push(arr[i]);
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
                pq.pop();
        }
        return ans;
    }
