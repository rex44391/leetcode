/*
* I use a bubble sort like way to solve this problem,
* first set the string in ascending order, 
* then swap two characters in the string,
* if they don't meet the requirement of S. 
* Do the above again and again until I can't make any swap.
* this algorithm works but is not very effective.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int s_len = 0;
    while(S[s_len] != '\0') {
        s_len += 1;
    }
    int *re = malloc(sizeof(int) * (s_len + 1) );
    *returnSize = s_len + 1;
    for(int i = 0; i < s_len + 1; i++) {
        re[i] = i;
    }
    
    
    while(true) {
        bool flag = false;
        for(int i = 1; i < s_len + 1; i++) {
            if(S[i - 1] =='D') {
                if(re[i] > re[i - 1]) {
                    int temp = re[i];
                    re[i] = re[i - 1];
                    re[i - 1] = temp;
                    flag = true;
                }
            } else { // == I
                if(re[i] < re[i - 1]) {
                    int temp = re[i];
                    re[i] = re[i - 1];
                    re[i - 1] = temp;
                    flag = true;
                }
            }
        }
        
        if(!flag) {
            break;
        }
    }
    return re;
}
