/*
* Using counting sort, beats other 100%
*/

typedef struct pair{
    int index;
    int counter;
} Pair;

int cmpfunc(const void * a, const void * b) {
    if( (*(Pair*)a).counter < (*(Pair*)b).counter)
        return 1;
    else
        return 0;
}

char* frequencySort(char* s) {
    Pair *table1 = malloc(sizeof(Pair) * 96);
    for(int i = 0; i < 96; i++) {
        table1[i].index = i;
        table1[i].counter = 0;
    }
    
    int s_len = 0;
    while(s[s_len] != '\0') {
        int pos = s[s_len] - ' ';
        table1[pos].counter++;
        s_len++;
    }
    
    qsort(table1, 96, sizeof(Pair), cmpfunc);
    
    int ptr1 = 0;

    char *re = malloc(sizeof(char) * 200000);
    int re_size = 0;
    while(ptr1 < 96) {
        if(ptr1 < 96 && table1[ptr1].counter == 0) {
            break;
        }
        char temp;
            temp = table1[ptr1].index + ' ';
            for(int i = 0; i < table1[ptr1].counter; i++) {
            re[re_size] = temp;
            re_size++;
        }
        ptr1++;
            
    }
    re[re_size] = '\0';
    return re;
}
