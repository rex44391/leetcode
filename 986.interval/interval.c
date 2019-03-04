/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RE_SIZE 2000

struct Interval* intervalIntersection(struct Interval* A, int ASize, struct Interval* B, int BSize, int* returnSize) {
    struct Interval* re = malloc(sizeof(struct Interval) * RE_SIZE);
    int re_size = 0;
    int a_pos = 0;
    int b_pos = 0;
    if(ASize == 0 || BSize == 0)
        return re;
    while(a_pos < ASize && b_pos < BSize) {
        if(A[a_pos].start < B[b_pos].start) {
            if(A[a_pos].end >= B[b_pos].start) {
                if(re[re_size].start != B[b_pos].start) {
                    re[re_size].start = B[b_pos].start;
                    if(A[a_pos].end < B[b_pos].end) {
                        re[re_size].end = A[a_pos].end;
                        a_pos++;
                    }
                    else {
                        re[re_size].end = B[b_pos].end;
                        b_pos++;
                    }
                    re_size++;
                    continue;
                }
            }
            a_pos++;
        } else {
            if(B[b_pos].end >= A[a_pos].start) {
                if(re[re_size].start !=  A[a_pos].start) {
                    re[re_size].start = A[a_pos].start;
                    if(B[b_pos].end < A[a_pos].end) {
                        re[re_size].end = B[b_pos].end;
                        b_pos++;
                    }
                    else {
                        re[re_size].end = A[a_pos].end;
                        a_pos++;
                    }
                    re_size++;
                    continue;
                }
            }
            b_pos++;
        }
        
    }
    
    //check the last segment
    if(a_pos < ASize) {
        for(int i = a_pos + 1; i < ASize; i++) {
            if(A[i].start <= B[BSize - 1].end) {
                if(A[i].start >= B[BSize - 1].start)
                    re[re_size].start = A[i].start;
                else
                    re[re_size].start = B[BSize - 1].start;
                if(A[i].end <= B[BSize - 1].end)
                    re[re_size].end = A[i].end;
                else
                    re[re_size].end = B[BSize - 1].end;
                re_size++;
            }
        }
    } else {
        for(int i = b_pos + 1; i < BSize; i++) {
            if(B[i].start <= A[ASize - 1].end) {
                if(B[i].start >= A[ASize - 1].start)
                    re[re_size].start = B[i].start;
                else
                    re[re_size].start = A[ASize - 1].start;
                if(B[i].end <= A[ASize - 1].end)
                    re[re_size].end = B[i].end;
                else
                    re[re_size].end = A[ASize - 1].end;
                re_size++;
            }
        }
    }
    
    
    *returnSize = re_size;
    return re;
}
