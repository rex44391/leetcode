/*
* my algorithm is ugly but the concept is easy.
* it's just brute-force to search all the answer
* Since the A just has 4 digits, we know that at most we have 24
* different combinations to check.
* for a scale so small like this one, brute force is always the most efficient
*/

bool isValid(int i, int j, int k, int l) {
    if(i * 10 + j > 23) return false;
    if(k * 10 + l > 59) return false;
    return true;
}

bool compr(int *best, int *cand) {//best lose:true, best win: false
    
    //compare hr
    int best_hr = best[0] * 10 + best[1];
    int cand_hr = cand[0] * 10 + cand[1];
    
    if(best_hr < cand_hr)
        return true;
    else if(best_hr > cand_hr)
        return false;
    
    //compare min
    int best_min = best[2] * 10 + best[3];
    int cand_min = cand[2] * 10 + cand[3];

    if(best_min < cand_min)
        return true;
    
    return false;
}

char* largestTimeFromDigits(int* A, int ASize) {
    
    int *best = malloc(sizeof(int) * 4);
    for(int i = 0; i < 4; i++)
        best[i] = -1;
    
    //brute force to loop all combinations
    for(int i = 0; i < ASize; i++) {
        for(int j = 0; j < ASize; j++) {
            for(int k = 0; k < ASize; k++) {
                for(int l = 0; l < ASize; l++) {
                    if(i != j && i != k && i != l && j != k && j != l && k != l) {
                        if(isValid(A[i], A[j], A[k], A[l])) {
                            if(best[0] == -1) {
                                best[0] = A[i];
                                best[1] = A[j];
                                best[2] = A[k];
                                best[3] = A[l];
                            } else {
                                int *cand = malloc(sizeof(int) * 4);
                                cand[0] = A[i];
                                cand[1] = A[j];
                                cand[2] = A[k];
                                cand[3] = A[l];
                                if(compr(best, cand)) {
                                    for(int x = 0; x < 4; x++) {
                                        best[x] = cand[x];
                                    } 
                                }
                                free(cand);
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(best[0] == -1)
        return "";
    else {
        char *re_char = malloc(sizeof(char) * 6);
        re_char[0] = best[0] + '0';
        re_char[1] = best[1] + '0';
        re_char[2] = ':';
        re_char[3] = best[2] + '0';
        re_char[4] = best[3] + '0';
        re_char[5] = '\0';
        return re_char;
    }
}
