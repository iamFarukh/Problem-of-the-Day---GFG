int countDistinctSubarray(int a[], int n)
    {
        unordered_set<int> myset;
        for(int i=0; i<n; i++) myset.insert(a[i]);
        
        unordered_map<int, int> m;
        int cnt = myset.size(), i = 0, j = 0, res = 0;
        
        while(j<n) {
            m[a[j]]++;
            while(i<=j and m.size()==cnt) {
                res += n-j;
                m[a[i]]--;
                if(m[a[i]]==0) {
                    m.erase(a[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
