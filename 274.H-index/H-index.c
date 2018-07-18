/*
* I just sort the citations array in descending order, 
* then check whether the looped element is >= h-index,
* if yes, I just return it. 
*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmpfunc);
    for(int i = 0; i < citationsSize; i++) {
        if(citations[citationsSize - i - 1] >= (citationsSize - i) )
            return citationsSize - i;
    }
    return 0;
}
