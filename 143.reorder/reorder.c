/*
* although it pass the test, this algorithm is slow, 
* because it need to search to tail every time(time complexity is O(n!))!
* but I think I can improve its efficiency by using an array 
* which stores all pointer of pointer to each node.
* Please check reorder1 for the improved one.
*/

void reorderList(struct ListNode* head) {
    if(!head) return;
    struct ListNode **ptr1 = &head;
    struct ListNode **ptr2 = &head;
    
    while(true) {
        while((*ptr2)->next) {
            ptr2 = &((*ptr2)->next);
        }
        if(ptr1 == ptr2 || (*ptr1)->next == *ptr2)
            break;
        
        (*ptr2)->next = (*ptr1)->next;
        (*ptr1)->next = (*ptr2);
        (*ptr2) = NULL;
        
        if((*ptr1)->next && (*ptr1)->next->next) {
            ptr1 = &((*ptr1)->next->next);
            ptr2 = ptr1;
            printf("%d, \n", (*ptr1)->val);
        } else {
            break;
        }

    }
    
}
