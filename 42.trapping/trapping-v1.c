/*
* My first thought of this problem
* is to draw it on a 2d array, like the picture on leetcode website
* After that, I can just calculate whether an empty block of the grid 
* can trap water(go right/left side of the block and see whether it can touch a brick)
* This algorithm is correct but need O(n*h) space(n is the second greatest number in array)
* and it failed the test, because a test case has many great numbers makes it
* memory limit exceeded. 
*/

int trap(int* height, int heightSize) {
    int max_height = -1;
    int second_height = -1;
    for(int i = 0; i < heightSize; i++) {
        if(height[i] > max_height) {
            second_height = max_height;
            max_height = height[i];
            continue;
        }
        if(height[i] > second_height) {
            second_height = height[i];
        }
    }
    
    bool **graph = malloc(sizeof(bool*) * heightSize);
    for(int i = 0; i < heightSize; i++) {
        graph[i] = malloc(sizeof(bool) * second_height);
        if(height[i] >= second_height) {
            for(int j = 0; j < second_height; j++) {
                graph[i][j] = true;
            }
        } else {
            for(int j = 0; j < height[i]; j++) {
                graph[i][j] = true;
            }
            for(int j = height[i]; j < second_height; j++) {
                graph[i][j] = false;
            }
        }
    }
    
    int counter = 0;
    for(int i = 0; i < heightSize; i++) {
        for(int j = 0; j < second_height; j++) {
            if(!graph[i][j]) {
                bool up = false;
                bool down = false;
                for(int k = i - 1; k >= 0; k--) {
                    if(graph[k][j]) {
                        up = true;
                        break;
                    }
                }
                for(int k = i + 1; k < heightSize; k++) {
                    if(graph[k][j]) {
                        down = true;
                        break;
                    }
                }
                
                if(up && down)
                    counter++;
            }
        }
    }
    return counter;
}
