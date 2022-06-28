vector<int> changeBits(int N) {
        vector<int> arr(2);
        int bits = log2(N)+1;    // Getting Number of bits of the number.
        int ans = pow(2,bits)-1; // Getting the Changed Number
        int sub = ans-N;     
        arr[0]=sub; // Assigning their values to the Array.
        arr[1]=ans;
        return arr;
    }
