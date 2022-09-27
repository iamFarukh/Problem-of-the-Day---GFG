//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int getBits(long long n){
        int setBits = 0;
        while(n>0){
            if(n%2 == 1)setBits++;
            n/=2;
        }
        return setBits;
    }
    int swapBitGame(long long N){
        // code here 
        int setBits = getBits(N);
        bool turn = true;
        while(setBits>0){
            turn =!turn;
            setBits--;
            
        }
        if(turn){
            return 2;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
