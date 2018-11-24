/*
* just recursive!
* The idea is that I assume the last bit is actually the 1-bit
* And recursivly check whther the remaining string can be constructed by 1-bit and 2-bit
* if yes, then return true.
*/

bool re;//set return variable to global would be easier

void recur(int *bits, int bitsSize) {
    if(re)//believe it or not, this if check is crucial to performance
        return;
    if(bitsSize == 1) {//init condition
        if(bits[0] == 0)
            re = true;
        return;
    }
    
    if(bitsSize == 2) {//init condition
        if(bits[0] == 1) {
            re = true;
            return;
        }
    }
    
    if(bits[bitsSize - 1] == 0) {
        recur(bits, bitsSize - 1);
        if(bits[bitsSize - 2] == 1) {
            recur(bits, bitsSize - 2);
        }
    } else {//bits[bitsSize - 1] == 1
        if(bits[bitsSize - 2] == 0) {
            return;
        } else {
            recur(bits, bitsSize - 2);
        }
    }
    
}


bool isOneBitCharacter(int* bits, int bitsSize) {
    if(bitsSize == 0 || bits[bitsSize - 1] != 0) return false;
    if(bitsSize == 1)
        return true;
    
    
    re = false;
    recur(bits, bitsSize - 1);
    
    return re;
}
