long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int  i =0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long int first = 0, second = 0;
        
        while(!pq.empty()){
            first *= 10;
            first += pq.top();
            pq.pop();
            if(!pq.empty()){
                second *= 10;
                second += pq.top();
                pq.pop();
            }
        }
        return (first+second);
    }
