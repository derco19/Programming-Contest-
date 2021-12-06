long minimumOneBitOperations(long n, long res = 0) {
    if (n == 0)
        return res;
    long b = 1;
    long p = (b<<1L);
    while (p <= n){
        b = p;
    }    
    return minimumOneBitOperations(p ^ b ^ n, res + b);
}

 

