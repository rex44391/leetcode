/* 
* After thinking more, I know I can reduce time complexity to just O(n)
* This solution combines concepts of counting sort and sliding window.
* First, create an array to record each alphabets' occurance in s1.
* Then, calculating the difference of occurances between s1 and the first window of s2
* (Here a window means a substring of s2 whose length is (len(s1),
* so the first window is s2's elements from 0 to len(s1) - 1)
* And for every remaining window, 
* updating the occurance based on the elements leveing the window
* and entering the windows
* that is, we don't have to calculate occurances of all the elements in every window
*/

bool checkInclusion(char* s1, char* s2) {
    if(!s1 || !s2) return false; 
    int *table = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++) 
        table[i] = 0;
		//a window has sometimes more occurances of an alphabet and sometimes less.
		//so we need two variables to record these two states
    int pos_sum = 0;
    int neg_sum = 0;
    
    int s1_len = 0;
    while(s1[s1_len] != '\0') {
        int pos = s1[s1_len] - 'a';
        table[pos]++;
        s1_len++;
    }
    pos_sum = s1_len;
    
    int s2_len = 0;
    while(s2[s2_len] != '\0') {
        s2_len++;
    }
    if(s1_len > s2_len)
        return false;
    
    for(int i = 0; i < s1_len; i++) {
        int pos = s2[i] - 'a';
        table[pos]--;
        if(table[pos] >= 0) {
            pos_sum--;
        } else {
            neg_sum++;
        }
    }
		//if both pos_sum and neg_sum is 0
		//then the window and s1 has the same occurances of all alphabets
    if(pos_sum == 0 && neg_sum == 0)
        return true;
    
    for(int i = 1; i <= s2_len - s1_len; i++) {
        //update exit
        int pos = s2[i - 1] - 'a';
        table[pos]++;
        if(table[pos] > 0) {
            pos_sum++;
        } else {
            neg_sum--;
        }
        //update enter
        pos = s2[i + s1_len - 1] - 'a';
        table[pos]--;
        if(table[pos] >= 0) {
            pos_sum--;
        } else {
            neg_sum++;
        }
        if(pos_sum == 0 && neg_sum == 0)
            return true;
    }
    return false;
}
