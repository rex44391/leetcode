int** permute(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0) {
        return NULL;
    } else if(numsSize == 1) {
       int **re = malloc(sizeof(int*));
       *returnSize = 1;
       re[0] = malloc(sizeof(int));
       re[0][0] = nums[0]; 
       return re;
   } else {
       int n_1_size = 0;
       int **n_1 = permute(nums, numsSize - 1, &n_1_size);
       *returnSize = n_1_size * numsSize;

       int **re = malloc(sizeof(int*) * (*returnSize) );
       for(int i = 0; i < (*returnSize) ; i++) {
           re[i] = malloc(sizeof(int) * numsSize);
       }

       int counter = 0;
       while(counter < (*returnSize) ) {
           int n_1_pos = counter / numsSize;
           int insert_pos = counter % numsSize;
           
           for(int i = 0; i < numsSize; i++) {
               if(i < insert_pos) {
                   re[counter][i] = n_1[n_1_pos][i];
               } else if (i == insert_pos) {
                   re[counter][i] = nums[numsSize - 1];
               } else {
                   re[counter][i] = n_1[n_1_pos][i - 1];
               }
           }
           
           counter++;
       }
       return re;
   }
}
