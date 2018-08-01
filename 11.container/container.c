/*
 * this algorithm is straightforward but not very efficient (22%)
 * I am planing to do some improvement with dynamic programming
 */


int maxArea(int* height, int heightSize) {
    if(heightSize < 2) return NULL;
    int max = INT_MIN;
    int max_height = INT_MIN;
    for(int i = 0; i < heightSize - 1; i++) {
        if(max_height > height[i])
            continue;
        for(int j = i + 1; j < heightSize; j++) {
            int hor = j - i;
            int ver = height[i];
            if(height[j] < ver)
                ver = height[j];
            
            int temp = hor * ver;
            if(temp > max) {
                max = temp;
                max_height = ver;
            }
        }
    }
    return max;
}
