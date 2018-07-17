/*
This is a very interesting problem.
If you use the most intutive algorithm(malloc an array and perform all the operation),
you will fail because of lack of memory.
So, you need to look only at ops array.
I just picked up the min of row and col index.
(that means the elements inside this area will increment most frequently)
And don't forget deal with the special case in which no operation performed! (see line 14)
*/


int maxCount(int m, int n, int** ops, int opsRowSize, int opsColSize) {
    if(m < 1 || n <  1) return NULL;
    if(opsRowSize < 1) return m*n;
    
    int row_min = INT_MAX;
    int col_min = INT_MAX;
    for(int op = 0; op < opsRowSize; op++) {
        if(ops[op][0] < row_min)
            row_min = ops[op][0];
        
        if(ops[op][1] < col_min)
            col_min = ops[op][1];
    }
    
    
    return row_min*col_min;
}
