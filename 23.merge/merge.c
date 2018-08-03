/*
* First concatenate every lists into one list
* Then sort them. This works but not very efficient
*/


struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode *prev = head;
    struct ListNode *ptr = head->next;
    while(ptr) {
        struct ListNode **find = &head;
        bool swap = false;
        while( (*find) != ptr) {
            if(((*find)->val) > ptr->val) {
                prev->next = ptr->next;
                ptr->next = (*find);
                *find = ptr;
                ptr = prev->next;
                swap = true;
                break;
            }
            find = &((*find)->next);
        }
        if(!swap) {
            prev = prev->next;
            ptr = ptr->next;
        }
    }
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *re_head = NULL;
    struct ListNode **pptr = &re_head;
    
    for(int i = 0; i < listsSize; i++) {
        struct ListNode *list_ptr = lists[i];
        while(list_ptr) {
            (*pptr) = malloc(sizeof(struct ListNode));
            (*pptr)->val = list_ptr->val;
            (*pptr)->next = NULL;
            pptr = &((*pptr)->next);
            list_ptr = list_ptr->next;
        }

    }
    re_head = insertionSortList(re_head);
    return re_head;
}
