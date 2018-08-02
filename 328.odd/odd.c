/*
 * I use two pointers, one point to first node another to second
 * One is the head of odd list and another is even
 * Then using a counter to determine which one I need to append
 * finally assign the next of odd's tail to even's head
 */

struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || head->next == NULL) return head;
    struct ListNode *odd_head = head;
    struct ListNode *even_head = head->next;

    struct ListNode *ptr = even_head->next;
    struct ListNode *ptr1 = odd_head;
    struct ListNode *ptr2 = even_head;

    int counter = 0;
    while(ptr) {
        if(counter % 2 == 0) {//odd_head
            ptr1->next = ptr;
            ptr1 = ptr1->next;
        } else {//even_head
            ptr2->next = ptr;
            ptr2 = ptr2->next;
        }
        counter++;
        ptr = ptr->next;
    }
    ptr1->next = even_head;
    ptr2->next = NULL;
    //don't forget to set ptr2->next to NULL
    //if not doing this, Leetcode's test program will get into an infinite loop
    return odd_head;
}
