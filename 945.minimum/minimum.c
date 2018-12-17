/*
* using an array named table to record each number's frequency in A
* then, from 0 to the maximum in A,  
* for a number i in the table, count how many times we should increment
* and add the result to i + 1.
*/


int minIncrementForUnique(int* A, int ASize) {
    int *table = malloc(sizeof(int) * 41000);
    for(int i = 0; i< 41000; i++)
        table[i] = 0;
    
    for(int i = 0; i < ASize; i++) {
        table[A[i]] += 1;
    }
    
    int counter = 0;
    for(int i = 0; i < 41000; i++) {
        if(table[i] > 1) {
            counter += (table[i] - 1);
            table[i + 1] += (table[i] - 1);
        }
    }
    return counter;
}
