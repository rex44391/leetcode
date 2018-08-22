/*
* count two strings' occurrences of each alphabet
* and check whether each alphabet has same occurrences in the two strings 
*/

bool isAnagram(char* s, char* t) {
    int *s_count = malloc(sizeof(int) * 26);
    int *t_count = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++) {
        s_count[i] = 0;
        t_count[i] = 0;
    }
    
    int s_len = 0;
    while(s[s_len] != '\0') {
        int temp = s[s_len] - 'a';
        s_count[temp]++;
        s_len++;
    }
    int t_len = 0;
    while(t[t_len] != '\0') {
        int temp = t[t_len] - 'a';
        t_count[temp]++;
        t_len++;
    }
    if(s_len != t_len) return false;
    
    for(int i = 0; i < 26; i++) {
        if(s_count[i] != t_count[i])
            return false;
    }
    
    
    return true;
}
