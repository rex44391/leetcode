/*
* using recursive, and be ware of there are two paths when number is odd
* in such cases, you have to get the lengths of n+1 and n-1
* and of course make the shorter one as the length
*/

long recur(long n) {
    if(n == 1) return 0;//terminal condition
    if(n == 2) return 1;
    if(n % 2 == 0) return 1 + recur(n / 2);//even case
    
    long plus1 = 1 + recur(n + 1);//odd case
    long minus1 = 1 + recur(n - 1);//odd case
    if(plus1 < minus1)
        return plus1;
    else
        return minus1;
}


int integerReplacement(int n) {
    return recur((long)n);
}
