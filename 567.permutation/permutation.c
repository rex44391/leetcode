/* 
* At first, I used straight forward way to solve this
* Just check every s2's substring which has length equal to len(s1)
* its time complexity is over O(n^2) and failed the test because of time limite exceeded
*/

void cleanBool(bool *b, int size) {
    for(int i = 0; i < size; i++) 
        b[i] = false;
    return;
}

bool validateBool(bool *b, int size) {
    for(int i = 0; i < size; i++) {
        if(!b[i])
            return false;
    }
    return true;
}


bool checkInclusion(char* s1, char* s2) {
    int s1_len = 0;
    int s2_len = 0;
    while(s1[s1_len] != '\0')
        s1_len++;
    while(s2[s2_len] != '\0')
        s2_len++;
    
    if(s1_len == 0 || s2_len == 0 || (s1_len > s2_len) )
        return false;
    
    
    
    int upper_limit = s2_len - s1_len + 1;
    
    
    bool *b = (bool*)malloc(sizeof(bool) * s1_len);
    for(int i = 0; i < upper_limit; i++ ) {
        cleanBool(b, s1_len);
        for(int j = 0; j < s1_len; j++) {
            for(int k = i; k < i + s1_len; k++) {
                if(s1[j] == s2[k] && !b[k-i]) {
                    b[k-i] = true;
                    break;
                }
            }
        }
        if(validateBool(b, s1_len))
            return true;
    }
    return false;
}
