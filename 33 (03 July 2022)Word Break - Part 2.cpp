vector<string> res;
    map<string, bool> hash;
    public:
    void rec(int ind, string curr, string s, vector<string>& dict){
        if(ind == s.size())  res.push_back(curr);
        
        for(int i=ind;i<s.length();i++){
            string sub = s.substr(ind, i-ind+1);
            if(hash.find(sub) != hash.end()){
                string ne;
                if(curr == "")  ne = sub;
                else    ne = curr+" "+sub;
                rec(i+1, ne, s, dict);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto word: dict)    hash[word] = true;
        rec(0, "", s, dict);     
        return res;
    }
