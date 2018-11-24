/*
* one pass, 100% and 0ms
*/

bool validMountainArray(int* A, int ASize) {
    if(ASize < 3) return false;
    
    bool down = false;//whether we are going down
    
    if(A[0] >= A[1])
        return false;
    
    for(int i = 2; i < ASize; i++) {
        if(!down) {
            if(A[i] < A[i - 1])
                down = true;
        } else {
            if(A[i] >= A[i - 1])
                return false;
        }
    }
    if(down)
        return true;
    return false;
}
