/* brute force!
*/

bool isUgly(int num) {
    if(num == 1) return true;
    if(num < 1) return false;
    
    int temp = num;
    while(temp > 1) {
        if(temp % 2 == 0) {
            temp /= 2;
            continue;
        }
        if(temp % 3 == 0) {
            temp /= 3;
            continue;
        }
        if(temp % 5 == 0) {
            temp /= 5;
            continue;
        }
        return false;
    }
    return true;
}
