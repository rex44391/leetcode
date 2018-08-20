/*
* The concept of this is easy, just using mod to get the next char.
* The only thing you need to be careful is that,
* Excel column starts from 1, and therefore when you mod 26 and get 0,
* that actually means you get a Z not an A.
* And in the loop everytime when n is 26's multiple, 
* n need to minus 1 after divided by 26!
*/

char* convertToTitle(int n) {
    
    char *re = malloc(sizeof(char) * 1000);
    int re_size = 0;
    
    while(n > 0) {
        if(n % 26 == 0) {
            re[re_size] = 'Z';
        } else {
            re[re_size] = (n % 26) + '@';
        }
        
        re_size++;
        
        if(n % 26 == 0) {
            n /= 26;
            n--;
        } else {
            n /= 26;
        }

        
    }
    
    char *re1 = malloc(sizeof(char) * 1000);
    int re1_size = 0;
    for(int i = re_size - 1; i > -1; i--) {
        re1[re1_size] = re[i];
        re1_size++;
    }
    re1[re1_size] = '\0';
    re1_size++;
    return re1;
}
