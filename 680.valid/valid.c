/*
* just loop from head and tail to check 
* whether the string is a palindrome
* if we found that at some position, it's not a palindrome
* we first try to omit the left one(delete the left one), then continue to check
* if not, we omit right one and check
* if either cases can't work, just return false
*/


bool validPalindrome(char* s) {
    int s_len = 0;
    while(s[s_len] != '\0')
        s_len++;
    if(s_len < 3)
        return true;
    
    int left = 0;
    int right = s_len - 1;
    
    bool b_point = false;
    while(left < right) {
        if(s[left] != s[right]) {
            b_point = true;
            break;
        }
        right -= 1;
        left += 1;
    }
    
    if(!b_point)
        return true;
    else {
        //try del left
        int temp_left = left;
        int temp_right = right;
        left += 1;
        b_point = false;
        while(left < right) {
            if(s[left] != s[right]) {
                b_point = true;
                break;
            }
            right -= 1;
            left += 1;
        }
        
        //try del right
        temp_right -= 1;
        if(!b_point)
            return true;
        else {
            while(temp_left < temp_right) {
                if(s[temp_left] != s[temp_right]) {
                    return false;
                }
                temp_right -= 1;
                temp_left += 1;
            }
        }
    }
    return true;
}
