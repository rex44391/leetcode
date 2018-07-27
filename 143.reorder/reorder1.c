/* In this version, I use an array to write down all pointers of the list
* and therefore, I don't need to get to the tail by searching all the list everytime
* although the space complexity goes up to O(n)
* the improvement of time complexity is significant(from O(n^2) to O(n)),
* It beats 100% of other submissions(the last version is the slowest!)
* shortening the execution time from 686 ms to 8ms!!! 
*/

void reorderList(struct ListNode* head) {
    int l_len = 0;
    struct ListNode *ptr = head;
    while(ptr) {
        l_len++;
        ptr = ptr->next;
    }
    struct ListNode **table = malloc(sizeof(struct ListNode) * l_len);
    ptr = head;
    for(int i = 0; i < l_len; i++) {
        table[i] = ptr;
        ptr = ptr->next;
    }
    
    int left = 0;
    int right = l_len - 1;
    struct ListNode **pptr = &head;
    while(left <= right) {
        if(left == right) {
            *pptr = table[left];
            (*pptr)->next = NULL;
            break;
        }
        *pptr = table[left];
        (*pptr)->next = table[right];
        (*pptr)->next->next = NULL;
        pptr = &((*pptr)->next->next);
        left++;
        right--;
    }
}
