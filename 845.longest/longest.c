/*
* 
* Just loop the array and find the mountain in the array(and beats 100%).
* The only thing we need to be careful is we need to know the status during the loop.
* We need to know are we going to downward or we are starting to climb a mountain. 
*/

int longestMountain(int* A, int ASize) {
    int start = -1;//recording a mountain's start
    bool count = false;//indicating whether we are walking in a mountain
    bool down = false;//indicating whether we are walking downward
    int max_len = 0;
    
    for(int i = 0; i < ASize - 1; i++) {
        
        if(A[i] < A[i + 1]) {
            if(count == false) {
                count = true;
                start = i;
            } else {// count == true
                if(down) {
                    int temp_len = ((i - 1) - start) + 2;
                    if(temp_len >= 3 && temp_len > max_len) {
                        max_len = temp_len;
                    }
                    start = i;
                    down = false;
                }
            }
        } else if(A[i] == A[i + 1]) {
            if(count) {
                int temp_len = ((i - 1) - start) + 2;
                if(temp_len >= 3 && temp_len > max_len) {
                    max_len = temp_len;
                }
                start = i;
                count = false;
                down = false;
            }
        } else {//count == -1
            if(count) {
                if(!down) {
                    down = true;
                }
            }
        }
    }
    if(count && down) {
        int temp_len = ((ASize - 2) - start) + 2;
        if(temp_len >= 3 && temp_len > max_len) {
            max_len = temp_len;
        }
    }
    
    
    return max_len;
}
