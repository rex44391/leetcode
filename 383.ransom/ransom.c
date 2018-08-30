/*
* Using counting algorithm
* And of course, you can modify this to use only one array to do counting for the two strings
*/

bool canConstruct(char* ransomNote, char* magazine) {
    int *r = malloc(sizeof(int) * 26);//for ransom note
    int *m = malloc(sizeof(int) * 26);//for magazine
    for(int i = 0; i < 26; i++) {
        r[i] = 0;
        m[i] = 0;
    }
    
    int r_len = 0;
    while(ransomNote[r_len] != '\0') {
        //count ransom note
				int pos = ransomNote[r_len] - 'a';
        r[pos]++;
        r_len++;
    }
    int m_len = 0;
    while(magazine[m_len] != '\0') {
				//count magazine
        int pos = magazine[m_len] - 'a';
        m[pos]++;
        m_len++;
    }
    
    if(r_len > m_len)
        return false;
    
    for(int i = 0; i < 26; i++) {
				//just check whether magazine has enough alphabets
        if(r[i] > m[i])
            return false;
    }
    return true;
}
