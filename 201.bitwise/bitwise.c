

int rangeBitwiseAnd(int m, int n) {
    long temp = m;
    long limit = n;
    for(long i = temp + 1; i <= limit; i++) {
        if(temp == 0) 
            return 0;
        temp = temp & i;
    }
    return (int)temp;
}
