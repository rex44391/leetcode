/*
* Just using an array to record each alphabet's position
* Initial the array with a special symbol(here I use INT_MAX)
* If an alphabet is not in the string, the symbol of the array remains
* Once an alphabet occur more than once, 
* record it with another special symbol(here I use INT_MAX - 1)
* finally, using sorting to get the smallest position
*/

int cmpfunc (int * a, int * b) {
   if(*a >= *b) return 1;
    return 0;
}

int firstUniqChar(char* s) {
    int *table = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++)
        table[i] = INT_MAX;
    
    int ptr = 0;
    while(s[ptr] != '\0') {
        int temp = s[ptr] - 'a';
        if(table[temp] == INT_MAX) {//first occurance
            table[temp] = ptr;
        } else if(table[temp] != INT_MAX - 1) {//occur more than once
            table[temp] = INT_MAX -1;
        }
        ptr++;
    }
    
    
    qsort(table, 26, sizeof(int), cmpfunc);
    
    if(table[0] == INT_MAX || table[0] == INT_MAX - 1) return -1;
    return table[0];
}


