/*
* Because the last one needs extra space and exceeds the memory limit,
* I try to think whether I can save the drawing(that is the 2d space).
* After further analyzing last algorithm, I found that 
* I don't need to calculate whether each block can trap the water.
* Rather for each i in height array, I just need to find the max height of i's left side,
* and right side and calculate min(left max, right max), 
* then use this value to substract i's height(if i's heigh < min).
* However, it cannot pass all test cases in time, because I waste too much time on finding
* max height of each i's left and right side.
*/

int trap(int* height, int heightSize) {
    int counter = 0;
    for(int i = 0; i < heightSize; i++) {
        int left_height = 0;
        int right_height = 0;
        for(int j = i - 1; j >=0; j--) {
            if(height[i] < height[j] &&  left_height < height[j]) {
                left_height = height[j];
            }
        }
        
        for(int j = i + 1; j < heightSize; j++) {
            if(height[i] < height[j] &&  right_height < height[j]) {
                right_height = height[j];
            }
        }
        
        int min_height = left_height;
        if(min_height > right_height)
            min_height = right_height;
        
        if(min_height > height[i]) {
            printf("%d, ", min_height - height[i]);
            printf("i:%d\n", i);
            counter += (min_height - height[i]);
        }
    }
    return counter;
}
