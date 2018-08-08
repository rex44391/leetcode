/*
* To make last one more efficient, 
* I have to save the time when finding max heights for each element in height array.
* And I found that I don't need to update max for each element, 
* because when I find the i's max heights in both sides, 
* it is highly possible that i+1 shares the same max heights.
* so here is the new design and it's efficiency beats other 100% submissions.
*/


int trap(int* height, int heightSize) {
    int counter = 0;
    
    int left_max = height[0];
    int left_index = 0;
    
    int right_max = 0;
    int right_index = -1;
    
    int left_right_min = left_max;
    
    for(int i = 0; i < heightSize - 1; i++) {
        //update right
        if(i >= right_index) {
            right_max = 0;
            for(int j = i + 1; j < heightSize; j++) {
                if(height[j] > right_max) {
                    right_max = height[j];
                    right_index = j;
                }
            }
            
            //update left_right_min
            if(right_max > left_max)
                left_right_min = left_max;
            else
                left_right_min = right_max;
        }
        
        if(height[i] < left_right_min)
            counter += left_right_min - height[i];
        
        //update left
        if(height[i] >= left_max) {
            left_index = i;
            left_max = height[i];
            
            //update left_right_min
            if(right_max > left_max)
                left_right_min = left_max;
            else
                left_right_min = right_max;
        }
    }
    return counter;
}
