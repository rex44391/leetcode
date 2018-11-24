/*
* recursive!!
* a symbol in Kth pos, N row is generated from a symbol in K / 2 pos, N-1 row
* N is less than 30, so this problem is not big and therefore perfect for recusive
* the result beats 100% other submissions in 0ms
*/

int kthGrammar(int N, int K) {
    if(N == 1) return 0;
    if(K == 1) return 0;
    
    int prev;
    if(K % 2 > 0)
        prev = (K / 2) + 1;
    else
        prev = K / 2;
    
    if(kthGrammar(N - 1, prev) == 1) {
        if(K % 2 == 0)
            return 0;
        else
            return 1;
    } else { // == 0
        if(K % 2 == 0)
            return 1;
        else
            return 0;
    }
}
