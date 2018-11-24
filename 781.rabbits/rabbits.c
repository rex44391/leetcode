/*
* a math problem, solving this in 0ms
*/

int numRabbits(int* answers, int answersSize) {
    int *table = malloc(sizeof(int) * 1000);
		//since the answers have the length at most 1000
    for(int i = 0; i < 1000; i++)
        table[i] = 0;
    for(int i = 0; i < answersSize; i++) {
        table[answers[i]] += 1;//record each answer's frequency
    }
    int re = 0;
    
    for(int i = 0; i < 1000; i++) {
        if(table[i] == 0)
            continue;
        re += ( (table[i] / (i + 1) ) * (i + 1) );
        if( (table[i] % (i+1)) > 0)
            re += (i + 1);
    }
    
    return re;
}
