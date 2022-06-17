int findSubString(string str)
    {
        // Your code goes here  
        set<char>s; unordered_map<char,int>m;
        for(char c:str)
        s.insert(c);
        
        int i =0, j = 0, ans = str.size(), n = s.size(); 
        
        while(i<str.size())
        {    m[str[i]]++; 
        if(m.size()==n)
        {
            while(m[str[j]]>1) m[str[j++]]--;
            ans = min(ans, i-j+1); 
        }
        i++;  
        }
        return ans;
    }
