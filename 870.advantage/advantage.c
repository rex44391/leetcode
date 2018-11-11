/*
* define a new structure which contain B's index and B's value
* Then sort array A, and array B(in new structure)
* for an element bi in B, find the smallest element in A which is greater than bi
* this algorithm beats 100% of other solutions (exec time: 64ms)
*/

typedef struct {
    short index;
    int val;
} Pair;

int cmpfunc1 (int * a, const int * b) {
    if( *a > *b )
       return 1;
    return 0;
}

int cmpfunc2 (const Pair * a, const Pair * b) {
    if( a->val > b->val )
       return 1;
    return 0;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize) {
    Pair *b = malloc(sizeof(Pair) * BSize);
    for(int i = 0; i < BSize; i++) {
        b[i].index = i;
        b[i].val = B[i];
    }
    
    bool *check = malloc(sizeof(bool) * ASize);
    for(int i = 0; i < ASize; i++)
        check[i] = false;
    
    qsort(A, ASize, sizeof(int), cmpfunc1);
    qsort(b, BSize, sizeof(Pair), cmpfunc2);
    
    
    int a_index = 0;
    for(int i = 0; i < BSize; i++) {
        while(a_index < ASize && A[a_index] <= b[i].val ) {
            a_index++;
        }
        if(a_index == ASize) {
            for(int j = 0; j < ASize; j++) {
                if(!check[j]) {
                    B[b[i].index] = A[j];
                    check[j] = true;
                    break;
                }
            }
        } else {
            B[b[i].index] = A[a_index];
            check[a_index] = true;
            a_index++;
        }
    }
    
    *returnSize = BSize;
    return B;
}
