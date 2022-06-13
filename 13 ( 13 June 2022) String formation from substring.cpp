class Solution{
public:	
		
	int isRepeat(string s)
{
    // Your code goes here
    string str = s + s;
    string new_str = str.substr(1,str.size()-2);
    
    if(new_str.find(s) != -1)
    {
        return 1;
    }
    else
        return 0;
}
};
