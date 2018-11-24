/*
* 100%, 0ms!
*/

typedef struct {
    int start;
    int end;
} Pair;

int maxChunksToSorted(int* arr, int arrSize) {
    if(arrSize == 0) return 0;
    
    Pair *p = malloc(sizeof(Pair) * arrSize);

    p[0].start = 0;
    p[0].end = arr[0];
    int p_size = 1;
    
    for(int i = 1; i < arrSize; i++) {
        int temp_start = i;
        int temp_end = arr[i];
        
        if(i > arr[i]) {
            temp_start = arr[i];
            temp_end = i;
        }
        bool check = false;
        for(int j = 0; j < p_size; j++) {
            if(temp_start >= p[j].start && temp_end <= p[j].end) {
                check = true;
                continue;
            }
            if(temp_start >= p[j].start && temp_start <= p[j].end) {
                p[j].end = temp_end;
                check = true;
                continue;
            }
            if(temp_end <= p[j].end && temp_end >= p[j].start) {
                p[j].start = temp_start;
                check = true;
                continue;
            }
        }
        if(!check) {
            p[p_size].start = temp_start;
            p[p_size].end = temp_end;
            p_size++;
        }
    }
    
    return p_size;
}
